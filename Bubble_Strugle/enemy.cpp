#include "enemy.h"

Enemy::Enemy(const float& r,const float& x,const float& y) : sf::CircleShape(r),radius(r)
{
    setPosition(x, y);
    setFillColor(sf::Color(150, 50, 200));
    setOutlineThickness(2);
    setOutlineColor(sf::Color::Black);
}

void Enemy::bounce(const int& W, const int& H)
{
    if (getGlobalBounds().top+getGlobalBounds().height>=H-200)
    {
        Velocity_y= -std::abs(Velocity_y);
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


void Enemy::jump(const sf::Time& elapsed, const int& W, const int& H)
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

Enemy::~Enemy()
{
    std::cerr<<"Jestem w destruktorze ball"<<std::endl;
}


