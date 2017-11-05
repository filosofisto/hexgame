//
// Created by Eduardo on 28/10/2017.
//
// zypper in SDL2-devel

#include "HexBoard.h"

HexBoard::HexBoard()
{
    build_hexagons();
}

HexBoard::~HexBoard()
{
    for (auto& hexagon: hexagons)
        delete hexagon;

    hexagons.clear();
}

/*void HexBoard::show_board()
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;

        if (SDL_CreateWindowAndRenderer(660, 480, 0, &window, &renderer) == 0) {
            SDL_bool done = SDL_FALSE;

            while (!done) {
                SDL_Event event;

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);

                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

                render_hexagons(renderer);

                SDL_RenderPresent(renderer);

                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        done = SDL_TRUE;
                    }
                }
            }
        }

        if (renderer) {
            SDL_DestroyRenderer(renderer);
        }
        if (window) {
            SDL_DestroyWindow(window);
        }
    }

    SDL_Quit();
}*/

void HexBoard::build_hexagons()
{
    int x1, x2, x3, y1, y2, y3, y4, scale = 20, next_x1 = 10;
    bool taked_next_x1;
    y1 = 10;

    for (int line = 0; line < 11; line++) {
        x1 = next_x1;
        taked_next_x1 = false;

        for (int column = 0; column < 11; column++) {
            x2 = x1 + scale;

            if (!taked_next_x1) {
                next_x1 = x2;
                taked_next_x1 = true;
            }

            x3 = x2 + scale;
            y2 = y1 + scale;
            y3 = y2 + scale;
            y4 = y3 + scale;

            Point *p1 = new Point(x1, y2), *p2 = new Point(x2, y1);
            Line *l1 = new Line(p1, p2);

            Point *p3 = new Point(x2, y1), *p4 = new Point(x3, y2);
            Line *l2 = new Line(p3, p4);

            Point *p5 = new Point(x3, y2), *p6 = new Point(x3, y3);
            Line *l3 = new Line(p5, p6);

            Point *p7 = new Point(x3, y3), *p8 = new Point(x2, y4);
            Line *l4 = new Line(p7, p8);

            Point *p9 = new Point(x2, y4), *p10 = new Point(x1, y3);
            Line *l5 = new Line(p9, p10);

            Point *p11 = new Point(x1, y3), *p12 = new Point(x1, y2);
            Line *l6 = new Line(p11, p12);

            Hexagon *hex = new Hexagon(l1, l2, l3, l4, l5, l6);
            hexagons.push_back(hex);

            x1 = x3;
        }

        y1 = y3;
    }
}

void HexBoard::render_hexagons(SDL_Renderer *pRenderer) const
{
    for (auto& hexagon: hexagons)
        hexagon->render(pRenderer);
}



