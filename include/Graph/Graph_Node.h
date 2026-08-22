#ifndef PATH_FINDING_GRAPH_NODE_H
#define PATH_FINDING_GRAPH_NODE_H

#include <raylib.h>
#include <string>
#include <vector>
#include "Edge.h"

class Graph_Node {

private:
    std::string name;

    Vector2 position;

    std::vector<Edge*> edges;

public:

    Graph_Node(
        const std::string& name,
        Vector2 position
    );

    std::string get_name() const;

    Vector2 get_position() const;

    void set_position(Vector2 position);

    void add_edge(Edge* edge);

    void remove_edge(Edge* edge);

    std::vector<Edge*>& get_edges();
};

#endif