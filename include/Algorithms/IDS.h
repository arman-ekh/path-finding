#ifndef PATH_FINDING_IDS_H
#define PATH_FINDING_IDS_H


class IDS : public Algorithm {

private:

    int current_limit;

    DLS dls;

public:

    void initialize(Graph& graph) override;

    void step() override;
};

#endif