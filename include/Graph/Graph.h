#ifndef PATH_FINDING_GRAPH_H
#define PATH_FINDING_GRAPH_H

class Algorithm {

public:

    virtual ~Algorithm() = default;

    virtual void initialize(
        Graph& graph
    ) = 0;

    virtual void step() = 0;

    virtual bool is_finished() const = 0;

    virtual bool is_found() const = 0;
};

#endif