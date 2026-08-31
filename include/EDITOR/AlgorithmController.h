#ifndef PATH_FINDING_ALGORITHMCONTROLLER_H
#define PATH_FINDING_ALGORITHMCONTROLLER_H
#include "..\Algorithms/Algorithm.h"

#include "..\Algorithms/BFS.h"
#include "..\Algorithms/DFS.h"
#include "..\Algorithms/DLS.h"
#include "..\Algorithms/UCS.h"
#include "..\Algorithms/IDS.h"

enum class AlgorithmType {
    BFS,
    DFS,
    DLS,
    IDS,
    UCS,
    GreedySearch
};

class AlgorithmController {
private:
    Graph* graph;
    Algorithm* algorithm = nullptr;
    AlgorithmType algorithm_type = AlgorithmType::GreedySearch;

    bool running = false;
    std::stack<Graph_Node*> path;

public:
    explicit AlgorithmController(Graph* graph);

    ~AlgorithmController();

    void set_algorithm(AlgorithmType type);

    void step();
    void reset();

    bool is_found() const;
    bool is_finished() const;

    AlgorithmType get_algorithm_type() const;

    Algorithm* get_algorithm() const;
};



#endif //PATH_FINDING_ALGORITHMCONTROLLER_H