#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include "defs.h"


class Player : public sf::Sprite
{
private:
    float time=0;
    std::string side="right";
    std::unique_ptr<sf::Texture> textura;
    std::unique_ptr<sf::Sprite> robot;
    std::vector<sf::IntRect>frame;
public:
    Player(const int& W,const int& H);
    friend class Scena;
    void animated(const sf::Time& elapsed);
    void run_right(const sf::Time& elapsed);
    void run_left(const sf::Time& elapsed);
};

#endif // PLAYER_H
