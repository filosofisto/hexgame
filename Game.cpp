//
// Created by eduardo on 11/5/17.
//

#include "Game.h"

Game::Game() {

}

Game::~Game() {

}

bool Game::init(string title, int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        cout << "SDL init success" << endl;

        if (SDL_CreateWindowAndRenderer(660, 480, 0, &window, &renderer) == 0) {
            cout << "Window creation success" << endl;
            cout << "Renderer creation success" << endl;

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        } else {
            cerr << "Window and Renderer creationa failed" << endl;
            return false;
        }
    } else {
        cerr << "SDL init failed" << endl;
        return false;
    }

    board = new HexBoard();
    running = true;
    return true;
}

bool Game::is_running() {
    return running;
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    board->render_hexagons(renderer);

    SDL_RenderPresent(renderer);
}

void Game::update() {

}

void Game::handle_events() {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;
            default:
                break;
        }
    }
}

void Game::clean() {
    if (window != 0)
        SDL_DestroyWindow(window);

    if (renderer != 0)
        SDL_DestroyRenderer(renderer);

    SDL_Quit();

    if (board != nullptr)
        delete board;
}
