#ifndef ENEMY_H
#define ENEMY_H
#pragma once
#include "defs.h"

class Enemy : public sf::CircleShape
{
private:
    float radius;
    float limit;
    float Velocity_x;
    float Velocity_y=0;
    float acceleration_y= 200;
public:
    bool kolizja_hero = false;
    bool kolizja_laser = false;
    Enemy(const float& r,const float& x,const float& y,const float& l,const float& V_x_);
    ~Enemy();
    void step(const sf::Time& elapsed, const int& W, const int& H);
    void bounce(const int& W, const int& H);
    float getRadius();
    float getLimit();
    void setVelocity_x(const float& v);
    void setLimit(const float& l);
    float getVelocity_x();
    void changeAcceleration_y();
};

#endif // ENEMY_H
