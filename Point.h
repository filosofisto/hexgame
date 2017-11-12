//
// Created by eduardo on 11/3/17.
//

#ifndef HEXGAME_POINT_H
#define HEXGAME_POINT_H

#include <iostream>

using namespace std;

class Point {
public:
    Point();
    Point(int x, int y);
    ~Point();

    int get_x() const;

    int get_y() const;

    void set_xy(int x, int y);

    void log();
private:
    int x, y;
};


#endif //HEXGAME_POINT_H
