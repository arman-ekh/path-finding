#ifndef PATH_FINDING_A_STAR_H
#define PATH_FINDING_A_STAR_H
#include <set>

#include "Algorithm.h"


class A_Star : public Algorithm{
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