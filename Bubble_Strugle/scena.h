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
    float radius,x,y,V_x;
    bool dodano = false;
    std::vector<std::unique_ptr<sf::Sprite>> tlo;
    std::vector<std::unique_ptr<sf::Sprite>> sciany;
    std::vector<std::unique_ptr<sf::Texture>> textury;
    std::vector<Enemy*> Balls;
public:
    Scena(const int& W,const int& H);
    int getWidth();
    int getHeight();
    void draw(const sf::Time& elp,Player& hero,Weapon* laser);
    void loop(Player& hero);
    void Kolizja_B_H(Player& hero);
    void Kolizja_B_W(Weapon* laser);
};

#endif // SCENA_H
