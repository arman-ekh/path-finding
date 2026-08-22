#ifndef PATH_FINDING_DLS_H
#define PATH_FINDING_DLS_H
#include <set>
#include <stack>

#include "Algorithm.h"

class DLS : public Algorithm {

private:
    std::stack<Graph_Node*> stack;

    std::set<Graph_Node*> visited;

    Graph_Node* current = nullptr;

    Graph_Node* goal = nullptr;

    bool finished = false;
    bool found = false;
    int depth_limit;

public:
    void initialize(Graph& graph) override;

    void step() override;

    void set_depth_limit(int limit);

    bool is_finished() const override;

    bool is_found() const override;

    Graph_Node* get_current() const;

    const std::set<Graph_Node*>& get_visited() const;
};

#endif