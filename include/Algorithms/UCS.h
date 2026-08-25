#ifndef PATH_FINDING_UCS_H
#define PATH_FINDING_UCS_H

#include <queue>
#include <set>

#include "Algorithm.h"

class UCS : public Algorithm {
    private:
        std::vector<Graph_Node*> vector;

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
};

#endif