#include "scena.h"

int main()
{
    Scena s(1000,800);
    Player hero;
    while(s.getECTS()!=2)
    {
        if(s.getECTS()==0)
        {
            s.loop(hero);
        }
        if(s.getECTS()==1)
        {
            s.loop(hero);
        }
    }
    return 0;
}
