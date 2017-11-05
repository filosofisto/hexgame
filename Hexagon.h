//
// Created by eduardo on 11/3/17.
//

#ifndef HEXGAME_HEXAGON_H
#define HEXGAME_HEXAGON_H

#include <array>
#include "Line.h"

using namespace std;

class Hexagon {
public:
    Hexagon(Line *l1, Line *l2, Line *l3, Line *l4, Line *l5, Line *l6);
    ~Hexagon();

    Line *get_l1() const;

    Line *get_l2() const;

    Line *get_l3() const;

    Line *get_l4() const;

    Line *get_l5() const;

    Line *get_l6() const;

    void render(SDL_Renderer *renderer) const;
private:
    Line *l1, *l2, *l3, *l4, *l5, *l6;
};


#endif //HEXGAME_HEXAGON_H
