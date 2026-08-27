#ifndef PATH_FINDING_GRAPHEDITOR_H
#define PATH_FINDING_GRAPHEDITOR_H

#include "..\Graph/Graph_Node.h"
#include "..\Graph/Graph.h"

enum class EditorMode {
    SELECT,
    CREATE_NODE,
    CREATE_EDGE,
    DELETE,
    SET_GOAL
};

class GraphEditor {

private:

    Graph& graph;

    EditorMode mode;

    Graph_Node* selected_node = nullptr;

    void set_goal(Graph_Node* node);

public:

    GraphEditor(Graph& graph);

    void update();

    void draw();

    void set_mode(EditorMode mode);
// private:
    void handle_mouse();

    void create_node(float x , float y);

    void create_edge(int cost , Graph_Node* from , Graph_Node* to);

    void delete_node(Graph_Node* node);

    Graph_Node* get_node_at(Vector2 position);

    Graph_Node* get_node_at(std::string name);


};

#endif