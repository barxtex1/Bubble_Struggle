#ifndef ENEMY_H
#define ENEMY_H
#pragma once
#include "defs.h"

class Enemy : public sf::CircleShape
{
private:
    float Velocity_x=0;
    float Velocity_y=0;
public:
    Enemy(const float& r);
    void jump(const sf::Time& elapsed,const std::vector<std::unique_ptr<sf::Sprite>> &sciany);
};

#endif // ENEMY_H
