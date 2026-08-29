#ifndef PATH_FINDING_GRAPH_NODE_H
#define PATH_FINDING_GRAPH_NODE_H

#include <raylib.h>
#include <string>
#include <vector>
#include "Edge.h"

enum class NodeState {
    SELECTED,
    UNSEEN,
    SEEN,
    BEING_CHECKED,
    ADDED_TO_FRE,
    PATH
};

class Graph_Node {

private:
    std::string name;
    Vector2 position;
    int node_depth =0;

    std::vector<Edge*> edges;
    Graph_Node* father;

    int cost=0;
    NodeState state ;

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

    void set_cost(int cost);

    int get_cost();

    void set_state(NodeState state);

    NodeState get_state();

    void set_father(Graph_Node* father);

    Graph_Node* get_father();

    void set_node_depth(int depth);
    int get_node_depth();
};

#endif