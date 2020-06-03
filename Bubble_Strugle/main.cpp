#include "scena.h"

int main()
{
    Scena s(1000,800);
    Player hero(s.getWidth(),s.getHeight());
    s.loop(hero);
    return 0;
}
