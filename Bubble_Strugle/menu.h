#ifndef MENU_H
#define MENU_H
#pragma once
#include "defs.h"


class Menu
{
private:
    sf::RenderWindow window_;
    sf::Font font;
    sf::Text text_start;
    sf::Text text_sterow;
    sf::Text text_zrodl;
    sf::Text text_wyjscie;
public:
    Menu(const int& W,const int& H);
    void draw();
    void loop();
};

#endif // MENU_H
