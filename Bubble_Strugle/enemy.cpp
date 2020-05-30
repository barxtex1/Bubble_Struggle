#include "enemy.h"

Enemy::Enemy(const float& r) : sf::CircleShape(r)
{
    setPosition(100.0, 100.0);
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
    Velocity_y += elapsed.asSeconds()*100;
    move(Velocity_x*elapsed.asSeconds(),Velocity_y*elapsed.asSeconds());
    bounce(W,H);
}
