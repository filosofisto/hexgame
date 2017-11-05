//
// Created by eduardo on 11/4/17.
//

#ifndef HEXGAME_HEXGRAPH_H
#define HEXGAME_HEXGRAPH_H

#include <iostream>
#include <vector>
#include <deque>
#include "Graph.h"

using namespace std;

class HexGraph {
public:
    HexGraph();
    ~HexGraph();

private:
    Graph *graph;

    void build_graph();

    void make_node(int i, int j, deque<int> &deque);
};


#endif //HEXGAME_HEXGRAPH_H
