#include "weapon.h"

Weapon::Weapon(const float& x, const float& y)
{
    textura_wep = std::make_unique<sf::Texture>();
    if(!textura_wep->loadFromFile("Source/Laser/Lasers/laserBlue06.png")){
        throw("Could not load texture");
    }
    laser_ = std::make_unique<sf::Sprite>();
    laser_->setTexture(*textura_wep);
    laser_->setPosition(x,y);
}

Weapon::~Weapon()
{
    std::cerr<<"Jestem w destruktorze laser"<<std::endl;
}

void Weapon::Animate()
{
    if(laser_->getGlobalBounds().top>25)
    {
        laser_->setScale(1,-a);
    }
    else
    {
        fire_l = false;
    }
    a += 0.05;
}
