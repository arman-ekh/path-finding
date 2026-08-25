#ifndef PATH_FINDING_GRAPH_H
#define PATH_FINDING_GRAPH_H


#include <raylib.h>
#include <string>
#include <vector>

#include "Graph_Node.h"
#include "Edge.h"

class Graph {

private:
    int node_counter = 0;

    std::vector<Graph_Node*> nodes;
    std::vector<Edge*> edges;

    Graph_Node* start = nullptr;
    Graph_Node* goal = nullptr;

public:

    Graph();

    void add_node(
        const std::string& name,
        Vector2 position
    );

    void delete_node(Graph_Node* node);

    void add_edge(
        Graph_Node* from,
        Graph_Node* to,
        int cost
    );

    void delete_edge(Edge* edge);

    void set_start(Graph_Node* node);

    void set_goal(Graph_Node* node);

    Graph_Node* get_start();

    Graph_Node* get_goal();

    std::vector<Graph_Node*>& get_nodes();

    std::vector<Edge*>& get_edges();

    void reset_nodes();
};
#endif