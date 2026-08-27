#ifndef PATH_FINDING_GRAPH_RENDERER_H
#define PATH_FINDING_GRAPH_RENDERER_H
#include "..\Graph/Graph.h"

class GraphRenderer {
    private:
    void draw_edge(Graph& graph);
    void draw_node(Graph& graph);
    public:
    void draw(Graph& graph);
};
#endif