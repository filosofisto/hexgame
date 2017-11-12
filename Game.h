//
// Created by eduardo on 11/5/17.
//

#ifndef HEXGAME_GAME_H
#define HEXGAME_GAME_H

#include <SDL.h>
#include <string>
#include <iostream>
#include "HexBoard.h"
#include "commun.h"

using namespace std;

class Game {

public:
    static Game *Instance();

    bool init(string title, int width, int height);

    bool is_running();

    void render();

    void update();

    void handle_events();

    void clean();

    void quit();

private:
    Game();
    ~Game();

    static Game *_instance;

    bool running;
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    HexBoard *board;
    Position positions[121];
    Player turn;
};

typedef Game TheGame;

#endif //HEXGAME_GAME_H
