//
// Created by eduardo on 11/3/17.
//

#ifndef HEXGAME_LINE_H
#define HEXGAME_LINE_H

#include <SDL.h>
#include "Point.h"

class Line {
public:
    Line(Point *p1, Point *p2);
    ~Line();

    Point *get_p1() const;

    Point *get_p2() const;

    void render(SDL_Renderer* renderer) const;

private:
    Point *p1, *p2;
};


#endif //HEXGAME_LINE_H
