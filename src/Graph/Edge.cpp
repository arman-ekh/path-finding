#include "../../include/Graph/Edge.h"

#include <cmath>

#include "../../include/Algorithms/GreedySearch.h"

Edge::Edge(Graph_Node *from, Graph_Node *to, int cost) {
    this->from = from;
    this->to = to;
    int x = from->get_position().x - to->get_position().x;
    int y = from->get_position().y - to->get_position().y;

    this->cost = std::sqrt(x * x + y * y);
}

int Edge::get_cost(){
    return cost;
}

Graph_Node *Edge::get_from(){
    return from;
}

Graph_Node *Edge::get_to(){
    return to;
}
