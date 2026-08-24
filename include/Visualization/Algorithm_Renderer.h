#ifndef PATH_FINDING_ALGORITHM_RENDERER_H
#define PATH_FINDING_ALGORITHM_RENDERER_H

class Algorithm;
class Graph;

class AlgorithmRenderer {

public:

    void draw(
        Graph& graph,
        Algorithm& algorithm
    );
};

#endif