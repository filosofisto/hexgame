#ifndef HEXGAME_DISJOINTSET_H
#define HEXGAME_DISJOINTSET_H

class DisjointSet {
public:
    DisjointSet(int);

    virtual ~DisjointSet();

    int find(int u);

    void merge(int x, int y);

protected:

private:
    int *parent;
    int *rnk;
    int n;
};

#endif // HEXGAME_DISJOINTSET_H
