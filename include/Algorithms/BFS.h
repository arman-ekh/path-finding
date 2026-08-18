#ifndef PATH_FINDING_BFS_H
#define PATH_FINDING_BFS_H

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

    bool is_finished() const override;

    bool is_found() const override;
};


#endif