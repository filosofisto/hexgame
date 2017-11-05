//
// Created by eduardo on 11/3/17.
//

#include "Point.h"

Point::Point(int x, int y): x(x), y(y) {

}

Point::~Point() {

}

int Point::get_x() const {
    return x;
}

int Point::get_y() const {
    return y;
}
