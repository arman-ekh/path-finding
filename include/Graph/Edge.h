#ifndef PATH_FINDING_EDGE_H
#define PATH_FINDING_EDGE_H

#include "Graph_Node.h"

class Edge {

private:

    Graph_Node* from;
    Graph_Node* to;

    int cost;

public:

    Edge(
        Graph_Node* from,
        Graph_Node* to,
        int cost
    );

    Graph_Node* get_from() const;

    Graph_Node* get_to() const;

    int get_cost() const;
};

#endif //PATH_FINDING_EDGE_H