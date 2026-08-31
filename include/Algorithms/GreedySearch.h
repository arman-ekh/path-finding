#ifndef PATH_FINDING_GREEDYSEARCH_H
#define PATH_FINDING_GREEDYSEARCH_H
#include <set>

#include "Algorithm.h"


class GreedySearch : public Algorithm {
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

    static float manhattan_distance(Graph_Node* a, Graph_Node* b) {
        float delta_x = a->get_position().x - b->get_position().x;
        float delta_y = a->get_position().y - b->get_position().y;
        delta_x >0 ? delta_x : delta_x *= -1;
        delta_y>0 ? delta_y : delta_y *= -1;
        return delta_x +delta_y;
    };
};


#endif