#ifndef SCENA_H
#define SCENA_H
#pragma once
#include "player.h"
#include "enemy.h"
#include "weapon.h"

class Scena
{
private:
    int ECTS = 0;
    bool dodano = false;
    bool wygrana = false;
    bool przegrana = false;
    float sleep = 0;
    sf::RenderWindow window_;
    sf::Font font;
    sf::Text text;
    sf::Text text_lose;
    int Width,Height;
    bool fire = false;
    float radius = 100;
    float x,y,V_x,lim;
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
    void rozbicie(Enemy* b);
    int getECTS();
};

#endif // SCENA_H
