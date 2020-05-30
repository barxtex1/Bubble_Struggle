#ifndef SCENA_H
#define SCENA_H
#pragma once
#include "player.h"


class Scena
{
private:
    sf::RenderWindow window_;
    int Width,Height;
    std::vector<std::unique_ptr<sf::Sprite>> tlo;
    std::vector<std::unique_ptr<sf::Sprite>> sciany;
    std::vector<std::unique_ptr<sf::Texture>> textury;
public:
    Scena(const int& W,const int& H);
    void add_obiekt();
    int getWidth();
    int getHeight();
    void add_gift();
    void draw(const sf::Time& elp, Player& hero);
    void loop(Player& hero);
};

#endif // SCENA_H
