#include "../../include/Algorithms/IDS.h"

#include <iostream>
#include <ostream>

void IDS::initialize(Graph &graph) {
    dls.initialize(graph);
    current_limit =1;
    dls.set_depth_limit(current_limit);
    this->graph = &graph;
}

void IDS::step() {
    dls.step();
    if (dls.is_finished()) {
        std::cout << "depth limit : " << current_limit << std::endl;
        current_limit++;
        dls.set_depth_limit(current_limit);
        dls.initialize(*graph);
    }
}

bool IDS::is_finished() {
    return dls.is_finished();
}

bool IDS::is_found() {
    return dls.is_found();
}
