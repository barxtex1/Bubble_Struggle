#ifndef MENU_H
#define MENU_H
#pragma once
#include "defs.h"


class Menu
{
private:
    sf::Font font;
    sf::Text text_rozp;
    sf::Text text_sterow;
    sf::Text text_zrodl;
    sf::Text text_wyjsc;
    std::vector<sf::Text> texty;
    std::unique_ptr<sf::Sprite> tlo;
    std::unique_ptr<sf::Texture> textura;
    std::unique_ptr<sf::Sprite> robot;
    std::unique_ptr<sf::Texture> textura_robot;
    bool slct_rozp = false;
    bool slct_sterow = false;
    bool slct_zrodl = false;
    bool slct = false;
    bool slct_wyjsc = false;
public:
    Menu(const int& W,const int& H);
    void draw(sf::RenderWindow& window_);
    void loop(sf::RenderWindow& window_);
    void select(const sf::Event& event,sf::RenderWindow& window_);
};

#endif // MENU_H
