//
// Created by Eduardo on 28/10/2017.
//

#ifndef HEXGAME_HEXBOARD_H
#define HEXGAME_HEXBOARD_H

#include <SDL.h>
#include <vector>

#include "Line.h"
#include "Hexagon.h"

using namespace std;

class HexBoard {
public:
    HexBoard();
    ~HexBoard();

    void render_hexagons(SDL_Renderer *pRenderer) const;

private:
    vector<Hexagon*> hexagons;

    void build_hexagons();
};


#endif //HEXGAME_HEXBOARD_H
