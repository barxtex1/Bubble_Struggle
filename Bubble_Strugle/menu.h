#ifndef MENU_H
#define MENU_H
#pragma once
#include "defs.h"


class Menu
{
private:
    struct teksty
    {
        sf::Text text;
        bool slct;
        int nr;
        teksty(const sf::Text& t,const bool& s,const int& n): text(t),slct(s),nr(n){}
    };
    bool sl = false;
    bool t1 = false;
    bool t2 = false;
    bool t3 = false;
    bool t4 = false;
    sf::Font font;
    sf::Text text;
    sf::Text Powrot;
    std::vector<teksty> txt;
    std::vector<sf::Text> sterow;
    std::vector<std::unique_ptr<sf::Sprite>> sprite_sterow;
    std::unique_ptr<sf::Sprite> tlo;
    std::unique_ptr<sf::Texture> textura;
    std::unique_ptr<sf::Sprite> robot;
    std::unique_ptr<sf::Texture> textura_robot;
    std::unique_ptr<sf::Sprite> ster;
    std::unique_ptr<sf::Texture> textura_sterow;
public:
    Menu(const int& W,const int& H);
    void draw(sf::RenderWindow& window_);
    void loop(sf::RenderWindow& window_);
    void select(const sf::Event& event,sf::RenderWindow& window_);
    void CheckSelect();
};

#endif // MENU_H
