#ifndef PATH_FINDING_DFS_H
#define PATH_FINDING_DFS_H


#include <set>
#include <stack>

#include "Algorithm.h"

class DFS : public Algorithm {

private:
    std::stack<Graph_Node*> stack;

    std::set<Graph_Node*> visited;

    Graph_Node* current = nullptr;

    Graph_Node* goal = nullptr;

    bool finished = false;
    bool found = false;

public:
    void initialize(Graph& graph) override;

    void step() override;

    bool is_finished()  override;

    bool is_found() override;

    Graph_Node* get_current() const;

    const std::set<Graph_Node*>& get_visited() const;
};

#endif