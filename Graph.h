//
// Created by Eduardo on 28/10/2017.
//

#ifndef HEXGAME_GRAPH_H
#define HEXGAME_GRAPH_H

#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const int NO_PATH = -1;

class Graph {
public:
    Graph(int);

    Graph(string filename);

    ~Graph();

    /**
     * Better path (less long)
     */
    void dijkstra(int);

    /**
     * Kruscal Algorithm (Minimal Spanning Tree)
     */
    int kruscal_mst();

    /**
     * Prim Algorithm (Minimal Spanning Tree)
     */
    int prim_mst();

    friend ostream &operator<<(ostream &os, const Graph &graph);

    int v();

    int e();

    vector<int> neighbors(int);

    Graph &add_edge(int, int, int);

    void delete_edge(int, int);

    int get_node(int);

    void set_node(int, int);

    int get_edge(int, int);

    void set_edge(int, int, int);

    vector<pair<int, int>> get_kruscal_edges();

    vector<pair<int, int>> get_prim_edges();

protected:

private:
    int number_vertexes;
    int *dist;
    int **graph_data;
    vector<pair<int, int>> kruscal_edges;
    vector<pair<int, int>> prim_edges;

    int min_distance(int[], bool[]);

    vector<pair<int, pair<int, int>>> create_vector_from_internal_data();

};

#endif //HEXGAME_GRAPH_H
