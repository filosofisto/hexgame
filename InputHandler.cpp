//
// Created by eduardo on 11/11/17.
//

#include "InputHandler.h"

InputHandler *InputHandler::_instance = nullptr;

InputHandler::InputHandler(): mouse_position(new Point(0,0)) {
    initMouseButtonStates();
}

InputHandler *InputHandler::Instance() {
    if (_instance == nullptr)
        _instance = new InputHandler();

    return _instance;
}

void InputHandler::initMouseButtonStates() {
    for (int i = 0; i < 3; i++)
        mouseButtonStates.push_back(false);
}

InputHandler::~InputHandler() {
    delete mouse_position;
}

void InputHandler::update() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                TheGame::Instance()->quit();
                break;
            case SDL_MOUSEBUTTONDOWN:
                on_mouse_down(event);
                break;
            case SDL_MOUSEBUTTONUP:
                on_mouse_up(event);
                break;
            case SDL_MOUSEMOTION:
                on_mouse_move(event);
                break;
            default:
                break;
        }
    }
}

void InputHandler::on_mouse_down(SDL_Event &event) {
    if (event.button.button == SDL_BUTTON_LEFT)
        mouseButtonStates[LEFT] = true;
    if (event.button.button == SDL_BUTTON_MIDDLE)
        mouseButtonStates[MIDDLE] = true;
    if (event.button.button == SDL_BUTTON_RIGHT)
        mouseButtonStates[RIGHT] = true;
}

void InputHandler::on_mouse_up(SDL_Event &event) {
    if (event.button.button == SDL_BUTTON_LEFT)
        mouseButtonStates[LEFT] = false;
    if (event.button.button == SDL_BUTTON_MIDDLE)
        mouseButtonStates[MIDDLE] = false;
    if (event.button.button == SDL_BUTTON_RIGHT)
        mouseButtonStates[RIGHT] = false;
}

void InputHandler::on_mouse_move(SDL_Event& event) {
    mouse_position->set_xy(event.motion.x, event.motion.y);
}

bool InputHandler::get_mouse_button_states(int button_number) {
    return mouseButtonStates[button_number];
}

void InputHandler::clean() {

}

Point *InputHandler::get_mouse_position() const {
    return mouse_position;
}
