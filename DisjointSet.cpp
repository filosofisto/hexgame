#include "DisjointSet.h"

DisjointSet::DisjointSet(int n) : n(n) {
    parent = new int[n + 1];
    rnk = new int[n + 1];

    for (int i = 0; i <= n; ++i) {
        rnk[i] = 0;

        //every element is parent of itself
        parent[i] = i;
    }
}

DisjointSet::~DisjointSet() {
    delete[] parent;
    delete[] rnk;
}

int DisjointSet::find(int u) {
    if (u != parent[u])
        parent[u] = find(parent[u]);

    return parent[u];
}

void DisjointSet::merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (rnk[x] > rnk[y])
        parent[y] = x;
    else
        parent[x] = y;

    if (rnk[x] == rnk[y])
        rnk[y]++;
}
