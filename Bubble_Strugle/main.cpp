#include "scena.h"
#include "menu.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Bubble Strugle");
    Scena s(window.getSize().x,window.getSize().y);
    Player hero;
    Menu m(window.getSize().x,window.getSize().y);
    while(window.isOpen())
    {
        m.loop(window);
        while(s.getECTS()!=6 && s.getNofLife() >= 0)
        {
            s.loop(hero,window);
        }
        s.resetLife_Ects();
    }
    return 0;
}
