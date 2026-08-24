#ifndef PATH_FINDING_BFS_H
#define PATH_FINDING_BFS_H
#include <queue>
#include <set>

#include "Algorithm.h"
#include "..\Graph/Graph_Node.h"
#include "..\Graph\Graph.h"

class BFS : public Algorithm {

private:
    std::queue<Graph_Node*> queue;

    std::set<Graph_Node*> visited;

    Graph_Node* current = nullptr;

    Graph_Node* goal = nullptr;

    bool finished = false;
    bool found = false;

public:
    void initialize(Graph& graph) override;

    void step() override;

    bool is_finished()  override;

    bool is_found()  override;
};


#endif