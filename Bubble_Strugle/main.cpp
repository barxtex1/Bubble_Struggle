#include "scena.h"

int main()
{
    Scena s(1000,800);
    Player hero(s.getWidth(),s.getHeight());
    s.loop(hero);
    std::cerr<<"Wyszedlem z petli"<<std::endl;
//    if(s.getECTS()==1)
//    {
//        s.loop(hero);
//    }
    return 0;
}
