//
// Created by eduardo on 11/11/17.
//

#ifndef HEXGAME_GEOMETRY_H
#define HEXGAME_GEOMETRY_H

#include <iostream>
#include "Point.h"
#include <vector>

using namespace std;

// Define Infinite (Using INT_MAX caused overflow problems)
#define INF 10000

class Geometry {
public:
    static Geometry *Instance();

    bool is_inside(vector<Point> polygon, int n, Point p);

private:
    Geometry();

    ~Geometry();

    /**
     * Given three colinear points p, q, r, the function checks if point q lies on line segment 'pr'.
     *
     * @param p
     * @param q
     * @param r
     * @return
     */
    bool on_segment(Point& p, Point& q, Point& r);

    /**
     * To find orientation of ordered triplet (p, q, r).
     * The function returns following values
     * 0 --> p, q and r are colinear
     * 1 --> Clockwise
     * 2 --> Counterclockwise
     * @param p
     * @param q
     * @param r
     * @return
     */
    int orientation(Point& p, Point& q, Point& r);

    /**
     * The function that returns true if line segment 'p1q1' and 'p2q2' intersect.
     * @param p1
     * @param q1
     * @param p2
     * @param q2
     * @return
     */
    bool do_intersect(Point& p1, Point& q1, Point& p2, Point& q2);

    static Geometry *_instance;
};


#endif //HEXGAME_GEOMETRY_H
