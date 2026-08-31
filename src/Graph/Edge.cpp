#include "../../include/Graph/Edge.h"

#include "../../include/Algorithms/GreedySearch.h"

Edge::Edge(Graph_Node *from, Graph_Node *to, int cost) {
    this->from = from;
    this->to = to;
    this->cost = GreedySearch::manhattan_distance(from, to);
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
