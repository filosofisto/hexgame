//
// Created by eduardo on 11/5/17.
//

#include "Game.h"
#include "InputHandler.h"

Game *Game::_instance = nullptr;

Game *Game::Instance() {
    if (_instance == nullptr)
        _instance = new Game();

    return _instance;
}

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
    turn = Player::PLAYER_1;

    for (int i = 0; i < 121; i++)
        positions[i] = Position::FREE;

    return true;
}

bool Game::is_running() {
    return running;
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    board->render_hexagons(renderer, positions);

    SDL_RenderPresent(renderer);
}

void Game::update() {
    if (TheInputHandler::Instance()->get_mouse_button_states(LEFT)) {
        Point *mouse_position = TheInputHandler::Instance()->get_mouse_position();
        mouse_position->log();

        int hex_id = board->find_by_point(*mouse_position);

        if (hex_id > -1) {
            positions[hex_id] = turn == Player::PLAYER_1 ? Position::PLAYER_1 : Position::PLAYER_2;
            turn = turn == Player::PLAYER_1 ? Player::PLAYER_2 : Player::PLAYER_1;
        }
    }
}

void Game::handle_events() {
    TheInputHandler::Instance()->update();
}

void Game::clean() {
    TheInputHandler::Instance()->clean();

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    delete board;
}

void Game::quit() {
    running = false;
}
