#include "widgets.h"

Widgets::Widgets(const float& W, const float& H)
{
    // add time
    textura_time = std::make_unique<sf::Texture>();
    if(!textura_time->loadFromFile("Source/Laser/Lasers/laserBlue02.png")){
        throw("Could not load texture");
    }
    czas = std::make_unique<sf::Sprite>();
    czas->setTexture(*textura_time);
    czas->setRotation(270);
    czas->setScale(3,25.6);
    czas->setPosition(25,H-130);

    // add life

    textura_life = std::make_unique<sf::Texture>();
    if(!textura_life->loadFromFile("Source/Robot/PNG/Parts HD/headShock.png")){
        throw("Could not load texture");
    }
    zycie = std::make_unique<sf::Sprite>();
    zycie->setTexture(*textura_life);
}
