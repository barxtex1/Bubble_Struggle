#include "scena.h"

int main()
{
    Scena s(1000,800);
    Player hero(s.getWidth(),s.getHeight());
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
