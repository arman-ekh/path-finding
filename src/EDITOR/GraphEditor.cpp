#include "../../include/EDITOR/GraphEditor.h"


#include <cmath>
#include <iostream>
#include <ostream>
#include <raylib.h>

GraphEditor::GraphEditor(Graph &graph) : graph(graph) {
    this->graph = graph;
    this->mode = EditorMode::SELECT;
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

void GraphEditor::update() {
    handle_mouse();
}

Graph_Node *GraphEditor::get_node_at(std::string name) {
    for (auto node : graph.get_nodes()) {
        if (node->get_name() == name) {
            return node;
        }
    }
    return nullptr;
}

Graph_Node* GraphEditor::get_node_at(Vector2 position) {

    for (auto node : graph.get_nodes()) {

        Vector2 node_position = node->get_position();

        float dx = position.x - node_position.x;
        float dy = position.y - node_position.y;

        float distance = std::sqrt(dx * dx + dy * dy);

        if (distance <= 30) {
            return node;
        }
    }

    return nullptr;
}

void GraphEditor::handle_mouse() {
    Vector2 mouse = GetMousePosition();

    if (mode == EditorMode::SELECT &&
        IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
        if (selected_node != nullptr) {
            selected_node->set_state(NodeState::UNSEEN);
        }
        selected_node = get_node_at(mouse);
        if (selected_node != nullptr) {
            selected_node->set_state(NodeState::SELECTED);
        }
    }
}
