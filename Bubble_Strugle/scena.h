#ifndef SCENA_H
#define SCENA_H
#pragma once
#include "player.h"
#include "enemy.h"
#include "weapon.h"

class Scena
{
private:
    sf::RenderWindow window_;
    int Width,Height;
    bool fire = false;
    std::vector<std::unique_ptr<sf::Sprite>> tlo;
    std::vector<std::unique_ptr<sf::Sprite>> sciany;
    std::vector<std::unique_ptr<sf::Texture>> textury;
public:
    Scena(const int& W,const int& H);
    int getWidth();
    int getHeight();
    void draw(const sf::Time& elp, Player& hero,Enemy* ball,Weapon* laser);
    void loop(Player& hero,Enemy* ball);
};

#endif // SCENA_H
