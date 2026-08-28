#include "../../include/Algorithms/DFS.h"

#include <iostream>
#include <ostream>

void DFS::initialize(Graph &graph) {
    goal = graph.get_goal();
    current = graph.get_start();
    while (!stack.empty()) {
        stack.pop();
    }
    visited.clear();
    stack.push(current);
}

bool DFS::is_found() {
    found = (current == goal);
    return found;
}

Graph_Node *DFS::get_current() const {
    return current;
}

const std::set<Graph_Node *> &DFS::get_visited() const {
    return visited;
}

bool DFS::is_finished() {
    if (!found && stack.empty()) {
        return true;
    }
    return false;
}

void DFS::step() {
    if (stack.empty() || found)
        return;

    current = stack.top();
    stack.pop();
    if (current != goal) {
        current->set_state(NodeState::BEING_CHECKED);
    }

    std::cout << current->get_name() << std::endl;

    if (visited.contains(current)) {
        return;
    }

    visited.insert(current);

    int child_count = current->get_edges().size();

    for (int i = 0; i < child_count; i++) {
        Edge* edge = current->get_edges().at(i);
        Graph_Node* child_node = edge->get_to();
        if (!visited.contains(child_node)) {
            stack.push(child_node);
            if (current != goal) {
                child_node->set_state(NodeState::ADDED_TO_FRE);
            }
        }
    }
}
