#include "../../include/Visualization/Graph_Renderer.h"

#include <iostream>
#include <ostream>
#include <raylib.h>

void GraphRenderer::draw(Graph &graph) {
    draw_node(graph);
    draw_edge(graph);
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
        DrawCircle(node->get_position().x ,node->get_position().y ,30 , color);
    }
}
