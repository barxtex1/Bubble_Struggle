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
    std::cerr<<"Jestem w destruktorze"<<std::endl;
}

void Weapon::Animate(const sf::Time& elapsed)
{
    time += elapsed.asSeconds();
    if(laser_->getGlobalBounds().top>25)
    {
        for (double i=1;i<time;i+=0.001)
        {
            laser_->setScale(1,-i);
        }
    }
    else
    {
        fire_l = false;
    }
}
