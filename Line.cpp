//
// Created by eduardo on 11/3/17.
//

#include "Line.h"

Line::Line(Point *p1, Point *p2): p1(p1), p2(p2)
{

}

Line::~Line()
{
    if (p1 != nullptr)
        delete p1;

    if (p2 != nullptr)
        delete p2;
}

void Line::render(SDL_Renderer *renderer) const
{
    SDL_RenderDrawLine(renderer, p1->get_x(), p1->get_y(), p2->get_x(), p2->get_y());
}

Point *Line::get_p1() const
{
    return p1;
}

Point *Line::get_p2() const
{
    return p2;
}
