#include "../../include/Graph/Graph.h"

void Graph::add_node(const std::string &name, Vector2 position) {
    Graph_Node *node = new Graph_Node(name, position);
    this->nodes.push_back(node);
    this->node_counter++;
}

void Graph::add_edge(Graph_Node *from, Graph_Node *to, int cost) {
   Edge *edge = new Edge(from, to, cost);
    this->edges.push_back(edge);
    from->add_edge(edge);
}

void Graph::set_goal(Graph_Node *node) {
    this->goal = node;
}

void Graph::set_start(Graph_Node *node) {
    this->start = node;
}

void Graph::delete_node(Graph_Node* node) {

    if (node == nullptr) {
        return;
    }

    for (auto it = edges.begin(); it != edges.end();) {

        Edge* edge = *it;

        Graph_Node* from = edge->get_from();
        Graph_Node* to = edge->get_to();
        if (from == nullptr || to == nullptr) {
            return;
        }
        if (from == node || to == node) {

            from->remove_edge(edge);

            if (to != from)
                to->remove_edge(edge);

            delete edge;
            it = edges.erase(it);
        } else {
            ++it;
        }
    }

    for (auto it = nodes.begin(); it != nodes.end(); ++it) {
        if (*it == node) {
            nodes.erase(it);
            node_counter--;

            delete node;
            break;
        }
    }
}

void Graph::delete_edge(Edge *edge) {
    if (edge == nullptr) {
        return;
    }
    Graph_Node* from = edge->get_from();
    Graph_Node* to = edge->get_to();
    if (from != nullptr ) {
        from->remove_edge(edge);
    }
    if (to != nullptr ) {
        to->remove_edge(edge);
    }
    for (auto it = edges.begin(); it != edges.end();) {
        if (*it == edge) {
            edges.erase(it);
            delete edge;
        }
    }
}

std::vector<Edge *> &Graph::get_edges() {
    return edges;
}

std::vector<Graph_Node *> &Graph::get_nodes() {
    return nodes;
}

Graph_Node *Graph::get_goal() {
    return this->goal;
}
Graph_Node *Graph::get_start() {
    return this->start;
}

Graph::Graph() {
    nodes = std::vector<Graph_Node *>();
    edges = std::vector<Edge *>();
    start = nullptr;
    goal = nullptr;
    node_counter = 0;
}

void Graph::reset_nodes() {
    int node_counter = nodes.size();
    for (int i = 0; i < node_counter; i++) {
        nodes.at(i)->set_cost(0);
    }
}
