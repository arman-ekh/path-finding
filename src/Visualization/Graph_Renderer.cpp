#include "../../include/Visualization/Graph_Renderer.h"

#include <iostream>
#include <ostream>
#include <raylib.h>

void GraphRenderer::draw(Graph &graph) {
    draw_edge(graph);
    draw_node(graph);
}

void GraphRenderer::draw_edge(Graph &graph) {
    int node_count = graph.get_nodes().size();
    for (int i = 0; i < node_count; i++) {
        Graph_Node* from;
        Graph_Node* to;
        from = graph.get_nodes()[i];
        for (int j =0 ; j < from->get_edges().size(); j++) {
            to = from->get_edges()[j]->get_to();
            DrawLineEx(from->get_position() ,to->get_position() ,5 , BLACK);
        }
    }
}
void GraphRenderer::draw_node(Graph &graph) {
    int node_count = graph.get_nodes().size();
    for (int i = 0; i < node_count; i++) {
        Graph_Node* node;
        node = graph.get_nodes()[i];
        Color color;
        if (node->get_state() == NodeState::UNSEEN) {
             color = GRAY;
        }else {
             color = BLUE;
        }

        if (graph.get_goal() == node) {
            color = RED;
        }else if (graph.get_start() == node) {
            color = GREEN;
        }

        DrawCircle(node->get_position().x ,node->get_position().y ,30 , color);

        std::string name = node->get_name();

        int text_width = MeasureText(
            name.c_str(),
            20
        );

        DrawText(
            name.c_str(),
            node->get_position().x - text_width / 2,
            node->get_position().y - 10,
            20,
            WHITE
        );
    }
}
