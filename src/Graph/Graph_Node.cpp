#include "../../include/Graph/Graph_Node.h"

Graph_Node::Graph_Node(const std::string &name, Vector2 position) {
    this->name = name;
    this->position = position;
    this->cost = 0;
    this->node_depth = 0;
    this->state = NodeState::UNSEEN;
    this->father = nullptr;
}

void Graph_Node::add_edge(Edge *edge) {
    this->edges.push_back(edge);
}

std::vector<Edge *> &Graph_Node::get_edges() {
    return this->edges;
}

std::string Graph_Node::get_name() const {
    return this->name;
}

Vector2 Graph_Node::get_position() const {
    return this->position;
}

void Graph_Node::set_position(Vector2 position) {
    this->position = position;
}

void Graph_Node::remove_edge(Edge* edge) {
    for (auto it = edges.begin(); it != edges.end(); ++it) {
        if (*it == edge) {
            edges.erase(it);
            return;
        }
    }
}

int Graph_Node::get_cost() {
    return cost;
}

void Graph_Node::set_cost(int cost) {
    this->cost = cost;
}

void Graph_Node::set_state(NodeState state) {
    this->state = state;
}

NodeState Graph_Node::get_state() {
    return this->state;
}

void Graph_Node::set_father(Graph_Node *father) {
    this->father = father;
}

Graph_Node* Graph_Node::get_father() {
    return this->father;
}

int Graph_Node::get_node_depth() {
    return this->node_depth;
}

void Graph_Node::set_node_depth(int depth) {
    this->node_depth = depth;
}
