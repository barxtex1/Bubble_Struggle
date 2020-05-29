#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include "defs.h"


class Player : public sf::Sprite
{
private:
    std::unique_ptr<sf::Texture> textura;
    std::unique_ptr<sf::Sprite> robot;
    std::vector<sf::IntRect>frame;
public:
    Player(const int& W,const int& H);
    friend class Scena;
};

#endif // PLAYER_H
