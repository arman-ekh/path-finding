#include "../../include/EDITOR/GraphEditor.h"


#include <iostream>
#include <ostream>

GraphEditor::GraphEditor(Graph &graph) : graph(graph) {
    this->graph = graph;
}

void GraphEditor::create_edge(int cost , Graph_Node* from , Graph_Node* to ) {
    graph.add_edge(from , to , cost);
}

void GraphEditor::create_node(float x, float y) {
    int graph_size = graph.get_nodes().size();

    char name = 'A' + graph_size;

    Vector2 vector2(x, y);

    graph.add_node(std::string(1, name), vector2);
}

void GraphEditor::delete_node(Graph_Node* node) {
    graph.delete_node(node);
}

void GraphEditor::draw() {
    for (auto node : graph.get_nodes()) {
        std::cout << "node : " << node->get_name() << std::endl;
        std:: cout << "node " << node->get_name()  << "edges : " << std::endl;
        for (auto edge : node->get_edges()) {
            std::cout << edge->get_from()->get_name() << " --> " << edge->get_to()->get_name() << std::endl;
        }
    }
    std::cout << "edges: " <<std::endl;
    for (auto edge : graph.get_edges()) {
        std::cout << edge->get_from()->get_name() << " --> " << edge->get_to()->get_name() << std::endl;
    }
}

Graph_Node *GraphEditor::get_node_at(std::string name) {
    for (auto node : graph.get_nodes()) {
        if (node->get_name() == name) {
            return node;
        }
    }
    return nullptr;
}
