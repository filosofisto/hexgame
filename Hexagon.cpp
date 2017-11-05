//
// Created by eduardo on 11/3/17.
//

#include "Hexagon.h"

Hexagon::Hexagon(Line *l1, Line *l2, Line *l3, Line *l4, Line *l5, Line *l6):
        l1(l1), l2(l2), l3(l3), l4(l4), l5(l5), l6(l6)
{

}

Hexagon::~Hexagon()
{
    if (l1 != nullptr)
        delete l1;

    if (l2 != nullptr)
        delete l2;

    if (l3 != nullptr)
        delete l3;

    if (l4 != nullptr)
        delete l4;

    if (l5 != nullptr)
        delete l5;

    if (l6 != nullptr)
        delete l6;
}

void Hexagon::render(SDL_Renderer *renderer) const
{
    if (l1 != nullptr)
        l1->render(renderer);
    if (l2 != nullptr)
        l2->render(renderer);
    if (l3 != nullptr)
        l3->render(renderer);
    if (l4 != nullptr)
        l4->render(renderer);
    if (l5 != nullptr)
        l5->render(renderer);
    if (l6 != nullptr)
        l6->render(renderer);
}

Line *Hexagon::get_l1() const
{
    return l1;
}

Line *Hexagon::get_l2() const
{
    return l2;
}

Line *Hexagon::get_l3() const
{
    return l3;
}

Line *Hexagon::get_l4() const
{
    return l4;
}

Line *Hexagon::get_l5() const
{
    return l5;
}

Line *Hexagon::get_l6() const
{
    return l6;
}
