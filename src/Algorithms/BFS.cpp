#include "../../include/Algorithms/BFS.h"

#include <iostream>

void BFS::initialize(Graph &graph) {
    goal = graph.get_goal();
    current = graph.get_start();
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
    queue.pop();

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
            queue.push(child_node);
        }
    }
}
