#ifndef PATH_FINDING_GRAPHEDITOR_H
#define PATH_FINDING_GRAPHEDITOR_H

#include "..\Graph/Graph_Node.h"
#include "..\Graph/Graph.h"

class GraphEditor {

private:

    Graph& graph;

    Graph_Node* selected_node = nullptr;

public:

    GraphEditor(Graph& graph);

    void update();

    void draw();

private:
    void handle_mouse();

    void create_node();

    void create_edge();

    void delete_node();

    Graph_Node* get_node_at(Vector2 position);
};

#endif