#ifndef SCENA_H
#define SCENA_H
#pragma once
#include "player.h"
#include "enemy.h"
#include "weapon.h"
#include "widgets.h"

class Scena
{
private:
    int ECTS = 0;
    bool dodano = false;
    bool wygrana = false;
    bool przegrana = false;
    float sleep = 0;
    float start_sleep = 0;
    int numb_of_life = 3;
    sf::Font font;
    sf::Text text;
    sf::Text text_lose;
    sf::Text text_over;
    sf::Text text_win;
    sf::Text text_start;
    int Width,Height;
    bool fire = false;
    float radius = 100;
    float x,y,V_x,lim,lim_rozb;
    std::vector<std::unique_ptr<sf::Sprite>> tlo;
    std::vector<std::unique_ptr<sf::Sprite>> sciany;
    std::vector<std::unique_ptr<sf::Texture>> textury;
    std::vector<sf::Texture> textury_planet;
    std::vector<Enemy> Balls;
public:
    Scena(const int& W,const int& H);
    int getWidth();
    int getHeight();
    void draw(const sf::Time& elp,Player& hero,Weapon* laser,Widgets& wid,sf::RenderWindow& window);
    void loop(Player& hero,sf::RenderWindow& window);
    void Kolizja_B_H(Player& hero);
    void Kolizja_B_W(Weapon* laser);
    int getECTS();
    int getNofLife();
    void resetLife_Ects();
    std::vector<sf::Texture> getPlanet();
};

#endif // SCENA_H
