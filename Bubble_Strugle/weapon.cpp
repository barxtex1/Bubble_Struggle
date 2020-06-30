#include "weapon.h"

Weapon::Weapon(const float& x, const float& y)
{
    textura_wep = std::make_unique<sf::Texture>();
    if(!textura_wep->loadFromFile("Resources/Laser/Lasers/laserBlue06.png")){
        throw("Could not load texture");
    }
    laser_ = std::make_unique<sf::Sprite>();
    laser_->setTexture(*textura_wep);
    laser_->setPosition(x,y);
}


void Weapon::Animate(const sf::Time& elapsed)
{
    time_wep += elapsed.asSeconds();
    if(laser_->getGlobalBounds().top>25)
    {
        laser_->setScale(1,-time_wep*25);
    }
    else
    {
        fire_l = false;
    }
}
