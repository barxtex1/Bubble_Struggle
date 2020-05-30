#include "enemy.h"

Enemy::Enemy(const float& r) : sf::CircleShape(r)
{
    setPosition(200.0, 200.0);
    setFillColor(sf::Color(150, 50, 200));
}

void Enemy::jump(const sf::Time& elapsed,const std::vector<std::unique_ptr<sf::Sprite>> &sciany)
{
    Velocity_x += elapsed.asSeconds()*0;
    Velocity_y += elapsed.asSeconds()*75;
    move(Velocity_x*elapsed.asSeconds(),Velocity_y*elapsed.asSeconds());
    for (auto &s : sciany)
    {
        if (s->getGlobalBounds().intersects(getGlobalBounds()))
        {
            Velocity_y = -std::abs(Velocity_y);
        }
    }
}
