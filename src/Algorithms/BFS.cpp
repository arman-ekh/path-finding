#include "../../include/Algorithms/BFS.h"

#include <iostream>

void BFS::initialize(Graph &graph) {
    goal = graph.get_goal();
    current = graph.get_start();
    while (!queue.empty()) {
        queue.pop();
    }
    visited.clear();
    queue.push(current);
}

bool BFS::is_finished() {
    finished = (queue.empty() && !found);
    return finished;
}

bool BFS::is_found() {
    found =  current == goal;
    return found;
}

void BFS::step() {
    if (queue.empty() || found)return;
    current = queue.front();
    if (current != goal) {
        current->set_state(NodeState::BEING_CHECKED);
    }
    queue.pop();



    if (visited.contains(current)) {
        return;
    }

    std::cout << current->get_name() << std::endl;
    visited.insert(current);

    int child_count = current->get_edges().size();

    for (int i = 0; i < child_count; i++) {
        Edge* edge = current->get_edges().at(i);
        Graph_Node* child_node = edge->get_to();
        if (!visited.contains(child_node)) {
            queue.push(child_node);
            if (current != goal) {
                if (child_node->get_father() == nullptr) {
                    child_node->set_father(current);
                }else {
                    if (child_node->get_father()->get_node_depth() >= current->get_node_depth()) {
                        child_node->set_father(current);
                    }
                }

                child_node->set_state(NodeState::ADDED_TO_FRE);
            }
        }
    }
}
