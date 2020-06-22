#include "enemy.h"

Enemy::Enemy(const float& r,const float& x,const float& y,const float& l,const float& V_x_, const std::vector<sf::Texture>& tex) : sf::CircleShape(r), radius(r),limit(l),Velocity_x(V_x_),textury_planet_(tex)
{
    setTexture(&textury_planet_[rand()%textury_planet_.size()]);
    setPosition(x, y);
}

void Enemy::bounce(const int& W, const int& H)
{
    if (getGlobalBounds().top+getGlobalBounds().height>=H-200)
    {
        Velocity_y = -std::abs(Velocity_y);
        Velocity_y = -limit;
    }
    else if(getGlobalBounds().top<=25)
    {
        Velocity_y = std::abs(Velocity_y);
    }
    else if(getGlobalBounds().left+getGlobalBounds().width>=W-25)
    {
        Velocity_x = -std::abs(Velocity_x);
    }
    else if(getGlobalBounds().left<=25)
    {
        Velocity_x = std::abs(Velocity_x);
    }
}


void Enemy::step(const sf::Time& elapsed, const int& W, const int& H)
{
    Velocity_y += elapsed.asSeconds()*acceleration_y;
    move(Velocity_x*elapsed.asSeconds(),Velocity_y*elapsed.asSeconds());
    bounce(W,H);
}

float Enemy::getRadius()
{
    return radius;
}

void Enemy::changeAcceleration_y()
{
    acceleration_y = acceleration_y/2;
}

float Enemy::getVelocity_x()
{
    return Velocity_x;
}

void Enemy::setVelocity_x(const float& v)
{
    Velocity_x = v;
}

float Enemy::getLimit()
{
    return limit;
}

void Enemy::setLimit(const float& l)
{
    limit = l;
}



