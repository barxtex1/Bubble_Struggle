#include "scena.h"
#include "menu.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Bubble Strugle");
    Scena s(window.getSize().x,window.getSize().y);
    Player hero;
    Menu m(window.getSize().x,window.getSize().y);
    m.loop(window);
    while(s.getECTS()!=3 && s.getNofLife() >= 0)
    {
        s.loop(hero,window);
    }
    return 0;
}
