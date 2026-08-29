#include "../../include/Algorithms/UCS.h"

#include <iostream>

void UCS::initialize(Graph &graph) {
    goal = graph.get_goal();
    current = graph.get_start();
    visited.clear();
    vector.clear();
    vector.push_back(current);
}

bool UCS::is_finished() {
    finished = (vector.empty() && !found);
    return finished;
}

bool UCS::is_found() {
    found = (current == goal);
    return found;
}

void UCS::step() {
    if (vector.empty() || found)return;
    int min_cost = INT_MAX;
    int vector_size = vector.size();
    int min_index = 0;
    for (int i = 0; i < vector_size; i++) {
        Graph_Node* node = vector.at(i);
        if (node->get_cost() < min_cost) {
            current = node;
            min_cost = node->get_cost();
            min_index = i;
        }
    }
    current = vector[min_index];
    vector.erase(vector.begin() + min_index);

    std::cout << current->get_name() << std::endl;
    if (current != goal) {
        current->set_state(NodeState::BEING_CHECKED);
    }

    if (visited.contains(current)) {
        return;
    }
    visited.insert(current);

    int child_count = current->get_edges().size();

    for (int i = 0; i < child_count; i++) {
        Edge* edge = current->get_edges().at(i);
        Graph_Node* child_node = edge->get_to();
        if (!visited.contains(child_node)) {
            child_node->set_cost(current->get_cost() + edge->get_cost());
            vector.push_back(child_node);
            child_node->set_father(current);
            if (current != goal) {
                child_node->set_state(NodeState::ADDED_TO_FRE);
            }
        }
    }
}
