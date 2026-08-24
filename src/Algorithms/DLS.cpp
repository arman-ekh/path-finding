#include "../../include/Algorithms/DLS.h"

#include <iostream>

void DLS::initialize(Graph& graph) {

    while (!stack.empty())
        stack.pop();

    while (!children_index.empty())
        children_index.pop();

    goal = graph.get_goal();

    current = graph.get_start();

    found = false;
    finished = false;

    stack.push(current);
    children_index.push(0);
}
bool DLS::is_finished() {
    finished = (stack.empty() && !found);
    if (depth >= depth_limit) {
        return true;
    }
    return finished;
}

Graph_Node *DLS::get_current() const {
    return current;
}

const std::stack<int> &DLS::get_visited() const {
    return children_index;
}

bool DLS::is_found() {
    found =  (current != nullptr && current == goal);
    return found;
}

void DLS::set_depth_limit(int limit) {
    this->depth_limit = limit;
}

void DLS::step() {

    if (stack.empty() || found)
        return;

    current = stack.top();

    int index = children_index.top();

    int depth = stack.size() - 1;

    std::cout << "Current: "
              << current->get_name()
              << " depth: "
              << depth
              << "depth limit: "
              << depth_limit
              << std::endl;

    if (current == goal && depth <= depth_limit) {
        found = true;
        return;
    }

    int child_count = current->get_edges().size();

    if (index >= child_count || depth >= depth_limit) {

        stack.pop();
        children_index.pop();

        if (!children_index.empty()) {
            children_index.top()++;
        }

        return;
    }


    Edge* edge = current->get_edges().at(index);

    Graph_Node* child = edge->get_to();

    stack.push(child);
    children_index.push(0);
}

