#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include "defs.h"


class Player : public sf::Sprite
{
private:
    double time=0;
    bool kolizja_ball = false;
    std::string side="right";
    std::unique_ptr<sf::Texture> textura;
    std::unique_ptr<sf::Texture> textura_exp;
    std::unique_ptr<sf::Sprite> robot;
    std::unique_ptr<sf::Sprite> explosion;
    std::vector<sf::IntRect>frame;
    std::vector<sf::IntRect>frame_exp;

public:
    Player(const int& W,const int& H);
    friend class Scena;
    void animated(const sf::Time& elapsed,const std::vector<std::unique_ptr<sf::Sprite>> &sciany);
    void run_right(const sf::Time& elapsed);
    void run_left(const sf::Time& elapsed);
    void kolizja(const sf::Time& elapsed);
};

#endif // PLAYER_H
