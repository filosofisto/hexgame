//Using SDL and standard IO
#include <SDL.h>
#include <iostream>
#include "Game.h"

using namespace std;

int main(int argc, char **argv) {
    /*HexBoard *hexBoard = new HexBoard();
    hexBoard->show_board();


    delete hexBoard;*/

    Game *game = new Game();

    game->init("Hex Game", 660, 480);

    while (game->is_running()) {
        game->handle_events();
        game->update();
        game->render();
    }

    game->clean();

    delete game;

    return EXIT_SUCCESS;
}