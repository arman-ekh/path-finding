#ifndef PATH_FINDING_DLS_H
#define PATH_FINDING_DLS_H
#include <set>
#include <stack>

#include "Algorithm.h"

class DLS : public Algorithm {

private:
    std::stack<Graph_Node*> stack;
    std::stack<int> children_index;

    Graph_Node* current = nullptr;

    Graph_Node* goal = nullptr;

    bool finished = false;
    bool found = false;
    int depth_limit = 0;
    int depth = 0;

public:
    void initialize(Graph& graph) override;

    void step() override;

    void set_depth_limit(int limit);

    bool is_finished()  override;

    bool is_found()  override;

    Graph_Node* get_current() const;

    const std::stack<int>& get_visited() const;
};

#endif