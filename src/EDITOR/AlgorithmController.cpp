#include "..\..\include/EDITOR/AlgorithmController.h"

#include <iostream>

#include "../../include/Algorithms/A_Star.h"
#include "../../include/Algorithms/GreedySearch.h"

AlgorithmController::AlgorithmController(Graph* graph) {
    this->graph = graph;
    set_algorithm(AlgorithmType::BFS);
}

AlgorithmController::~AlgorithmController() {
    delete algorithm;
}

void AlgorithmController::set_algorithm(AlgorithmType type) {

    delete algorithm;
    algorithm = nullptr;

    algorithm_type = type;

    switch (type) {

        case AlgorithmType::BFS:
            algorithm = new BFS();
            break;

        case AlgorithmType::DFS:
            algorithm = new DFS();
            break;

        case AlgorithmType::DLS:
            algorithm = new DLS();
            break;

        case AlgorithmType::IDS:
            algorithm = new IDS();
            break;

        case AlgorithmType::UCS:
            algorithm = new UCS();
            break;

        case AlgorithmType::GreedySearch:
            algorithm = new GreedySearch();
            break;

        case AlgorithmType::A_star:
            algorithm = new A_Star();
            break;
    }

    reset();
}

void AlgorithmController::step() {
    if (algorithm != nullptr) {
        if (!algorithm->is_finished() && !algorithm->is_found()) {
            algorithm->step();
        }
        if (algorithm->is_found()) {
            Graph_Node* father = graph->get_goal();
            while (father != nullptr) {
                std::cout <<"path: " <<father->get_name() << std::endl;
                path.push(father);
                father = father->get_father();
            }
            graph->reset_nodes();
            algorithm->initialize(*graph);
            while (!path.empty()) {
                path.top()->set_state(NodeState::PATH);
                path.pop();
            }
        }
    }
}

void AlgorithmController::reset() {
    if (algorithm != nullptr) {
            graph->reset_nodes();
            algorithm->initialize(*graph);
        }
}

bool AlgorithmController::is_found() const {
    return algorithm != nullptr && algorithm->is_found();
}

bool AlgorithmController::is_finished() const {
    return algorithm == nullptr || algorithm->is_finished();
}

AlgorithmType AlgorithmController::get_algorithm_type() const {
    return algorithm_type;
}

Algorithm* AlgorithmController::get_algorithm() const {
    return algorithm;
}