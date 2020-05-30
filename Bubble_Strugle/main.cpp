#include "scena.h"

int main()
{
    Scena s(1000,800);
    Player hero(s.getWidth(),s.getHeight());
    Enemy* ball;
    s.loop(hero,ball);
    return 0;
}
