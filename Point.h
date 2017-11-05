//
// Created by eduardo on 11/3/17.
//

#ifndef HEXGAME_POINT_H
#define HEXGAME_POINT_H


class Point {
public:
    Point(int x, int y);
    ~Point();

    int get_x() const;
    int get_y() const;
private:
    int x, y;
};


#endif //HEXGAME_POINT_H
