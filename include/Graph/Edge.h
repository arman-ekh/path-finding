#ifndef PATH_FINDING_EDGE_H
#define PATH_FINDING_EDGE_H

class Graph_Node;

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

    Graph_Node* get_from();

    Graph_Node* get_to();

    int get_cost();
};

#endif