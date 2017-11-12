//
// Created by eduardo on 11/11/17.
//

#ifndef HEXGAME_INPUTHANDLER_H
#define HEXGAME_INPUTHANDLER_H

#include <SDL.h>
#include <vector>
#include "Game.h"

using namespace std;

enum MouseButtons
{
    LEFT, MIDDLE, RIGHT
};

class InputHandler
{
public:
    static InputHandler *Instance();

    void update();

    bool get_mouse_button_states(int button_number);

    Point *get_mouse_position() const;

    void clean();

private:
    InputHandler();

    ~InputHandler();

    void initMouseButtonStates();

    void on_mouse_down(SDL_Event& event);

    void on_mouse_up(SDL_Event& event);

    void on_mouse_move(SDL_Event& event);

    //Fields
    static InputHandler *_instance;

    vector<bool> mouseButtonStates;

    Point *mouse_position;
};

typedef InputHandler TheInputHandler;

#endif //HEXGAME_INPUTHANDLER_H
