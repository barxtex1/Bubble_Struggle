#ifndef ENEMY_H
#define ENEMY_H
#pragma once
#include "defs.h"

class Enemy : public sf::CircleShape
{
private:
    float Velocity_x=100;
    float Velocity_y=0;
    float radius;
    float acceleration_y=200;
public:
    bool kolizja_hero = false;
    bool kolizja_laser = false;
    Enemy(const float& r);
    void jump(const sf::Time& elapsed, const int& W, const int& H);
    void bounce(const int& W, const int& H);
    float getRadius();
    void changeAcceleration_y();
};

#endif // ENEMY_H
