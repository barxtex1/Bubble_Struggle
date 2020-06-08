#include "scena.h"

int main()
{
    Scena s(1000,800);
    Player hero;
    while(s.getECTS()!=2)
    {
        s.loop(hero);
    }
    return 0;
}
