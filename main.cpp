//Using SDL and standard IO
#include <SDL.h>
#include <iostream>
#include "Game.h"

using namespace std;

int main(int argc, char **argv) {
    TheGame::Instance()->init("Hex Game", 660, 480);

    while (TheGame::Instance()->is_running()) {
        TheGame::Instance()->handle_events();
        TheGame::Instance()->update();
        TheGame::Instance()->render();

        SDL_Delay(10);
    }

    TheGame::Instance()->clean();

    return EXIT_SUCCESS;
}