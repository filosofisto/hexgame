//
// Created by eduardo on 11/3/17.
//

#include "Point.h"

Point::Point(): x(0), y(0) {

}

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

void Point::set_xy(int x, int y) {
    this->x = x;
    this->y = y;
}

void Point::log() {
    cout << get_x() << ", " << get_y() << endl;
}
