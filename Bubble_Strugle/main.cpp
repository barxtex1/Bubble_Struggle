#include "scena.h"
#include "menu.h"

int main()
{
    Scena s(1000,800);
    Player hero;
    Menu m(s.getWidth(),s.getHeight());
    m.loop();
    while(s.getECTS()!=3 && s.getNofLife() >= 0)
    {
        s.loop(hero);
    }
    return 0;
}
