#ifndef PATH_FINDING_ALGORITHM_H
#define PATH_FINDING_ALGORITHM_H

#include "../Graph/Graph.h"

class Algorithm {

public:
    virtual ~Algorithm() = default;

    virtual void initialize(Graph& graph) = 0;

    virtual void step() = 0;

    virtual bool is_finished() = 0;

    virtual bool is_found() = 0;
};

#endif