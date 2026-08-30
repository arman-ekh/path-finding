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
    if (graph_size == 1 ) {
        graph.set_start(graph.get_nodes().at(0));
    }else if (graph_size > 1) {
        graph.set_goal(graph.get_nodes().at(graph_size-1));
    }
}

void GraphEditor::delete_node(Graph_Node* node) {
    if (graph.get_start() == node) {
        graph.delete_node(node);
        if (graph.get_nodes().size() >= 1) {
            Graph_Node* next_start = graph.get_nodes().at(0);
            if (next_start != nullptr) {
                if (next_start == graph.get_goal()) {
                    graph.set_goal(nullptr);
                }
                graph.set_start(next_start);
            }
        }
    }else {
        graph.delete_node(node);
    }

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

    if (IsKeyPressed(KEY_N)) {
        set_mode(EditorMode::CREATE_NODE);
    }

    if (IsKeyPressed(KEY_E)) {
        set_mode(EditorMode::CREATE_EDGE);
    }

    if (IsKeyPressed(KEY_S)) {
        set_mode(EditorMode::SELECT);
    }

    if (IsKeyPressed(KEY_D)) {
        set_mode(EditorMode::DELETE);
    }

    if (IsKeyPressed(KEY_G)) {
        set_mode(EditorMode::SET_GOAL);
    }

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
    }else if (mode == EditorMode::CREATE_NODE) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (get_node_at(mouse) == nullptr) {
                create_node(mouse.x, mouse.y);
            }
        }
    }else if (mode == EditorMode::CREATE_EDGE) {
        if (selected_node != nullptr) {
            DrawLineEx(selected_node->get_position(), mouse ,5 ,BLACK);
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (selected_node != nullptr) {
                selected_node->set_state(NodeState::UNSEEN);
                Graph_Node* node = get_node_at(mouse);

                if (node != nullptr && node != selected_node) {
                    create_edge(1 , selected_node, node);
                    selected_node = nullptr;
                }
            }else {
                selected_node = get_node_at(mouse);
                if (selected_node != nullptr) {
                    selected_node->set_state(NodeState::SELECTED);
                }
            }
        }
    }else if (mode == EditorMode::DELETE) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Graph_Node* node = get_node_at(mouse);
            if (node != nullptr) {
                delete_node(node);
            }
        }
    }else if (mode == EditorMode::SET_GOAL) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Graph_Node* node = get_node_at(mouse);
            if (node != nullptr) {
                set_goal(node);
            }
        }
    }
}

void GraphEditor::set_mode(EditorMode mode) {
    this->mode = mode;
}


void GraphEditor::set_goal(Graph_Node* node) {
    graph.set_goal(node);
}
