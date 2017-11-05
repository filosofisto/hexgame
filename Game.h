//
// Created by eduardo on 11/5/17.
//

#ifndef HEXGAME_GAME_H
#define HEXGAME_GAME_H

#include <SDL.h>
#include <string>
#include <iostream>
#include "HexBoard.h"

using namespace std;

class Game {

public:
    Game();
    ~Game();

    bool init(string title, int width, int height);

    bool is_running();

    void render();

    void update();

    void handle_events();

    void clean();

private:
    bool running;
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    HexBoard *board;

};


#endif //HEXGAME_GAME_H
