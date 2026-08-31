#include "../../include/Algorithms/A_Star.h"

#include <iostream>

#include "../../include/Algorithms/GreedySearch.h"

void A_Star::initialize(Graph &graph) {
    goal = graph.get_goal();
    current = graph.get_start();
    visited.clear();
    vector.clear();
    vector.push_back(current);
}

bool A_Star::is_finished() {
    finished = (vector.empty() && !found);
    return finished;
}

bool A_Star::is_found() {
    found = (current == goal);
    return found;
}

void A_Star::step() {
    if (vector.empty() || found)
        return;

    int min_cost = INT_MAX;
    int min_index = 0;

    for (int i = 0; i < vector.size(); i++) {
        Graph_Node* node = vector.at(i);

        int g = node->get_cost();
        int h = GreedySearch::manhattan_distance(node, goal);
        int f = g + h;

        if (f < min_cost) {
            min_cost = f;
            min_index = i;
        }
    }

    current = vector[min_index];
    vector.erase(vector.begin() + min_index);

    std::cout << current->get_name() << std::endl;
    std::cout << "g: " << current->get_cost() << std::endl;
    std::cout << "h: "
              << GreedySearch::manhattan_distance(current, goal)
              << std::endl;
    std::cout << "f: "
              << current->get_cost() +
                 GreedySearch::manhattan_distance(current, goal)
              << std::endl;

    if (current == goal) {
        found = true;
        return;
    }

    current->set_state(NodeState::BEING_CHECKED);

    if (visited.contains(current))
        return;

    visited.insert(current);

    int child_count = current->get_edges().size();

    for (int i = 0; i < child_count; i++) {
        Edge* edge = current->get_edges().at(i);
        Graph_Node* child_node = edge->get_to();

        if (visited.contains(child_node))
            continue;

        int new_cost = current->get_cost() + edge->get_cost();

        if (child_node->get_father() == nullptr ||
            new_cost < child_node->get_cost()) {

            child_node->set_cost(new_cost);
            child_node->set_father(current);

            vector.push_back(child_node);

            if (current != goal) {
                child_node->set_state(NodeState::ADDED_TO_FRE);
            }
            }
    }
}