#include "scena.h"

int main()
{
    Scena s(1000,800);
    Player hero(s.getWidth(),s.getHeight());
    Enemy* ball = nullptr;
    s.loop(hero,ball);
    delete ball;
    return 0;
}
