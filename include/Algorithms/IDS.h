#ifndef PATH_FINDING_IDS_H
#define PATH_FINDING_IDS_H


#include "Algorithm.h"
#include "DLS.h"


class IDS : public Algorithm {

private:

    int current_limit;
    Graph*graph = nullptr;
    DLS dls;

public:

    void initialize(Graph& graph) override;

    void step() override;

    bool is_finished()  override;

    bool is_found() override;
};

#endif