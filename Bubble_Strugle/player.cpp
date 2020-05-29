#include "player.h"

Player::Player(const int& W,const int& H)
{
    textura = std::make_unique<sf::Texture>();
    if(!textura->loadFromFile("Source/Robot/Tilesheet/character_robot_sheetHD.png")){
        throw("Could not load texture");
    }
    robot = std::make_unique<sf::Sprite>();
    robot->setTexture(*textura);
    robot->setTextureRect(sf::IntRect(0, 0, 192, 256));
    robot->setScale(0.5,0.5);
    robot->setPosition(W/2-25,H-329);
}
