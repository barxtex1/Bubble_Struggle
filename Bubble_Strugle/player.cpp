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
    robot->setOrigin(robot->getLocalBounds().width/2,0);
    robot->setScale(0.5,0.5);
    robot->setPosition(W/2-25,H-329);
    for (int i = 0;i<=1344;i+=192)
    {
        frame.emplace_back(sf::IntRect(i,1024, 192, 256));
    }
}

void Player::run_right(const sf::Time& elapsed)
{
    robot->move(elapsed.asSeconds()*100,0);
    for (int i=0;i<8;i++)
    {
        if(time>i-0.9*i) robot->setTextureRect(frame[i]);
        if(time>=0.80) time=0;
    }
    if(side!="right")
    {
        robot->setOrigin(robot->getLocalBounds().width/2,0);
        robot->setScale(0.5,0.5);
        side = "right";
    }
}

void Player::run_left(const sf::Time& elapsed)
{
    robot->move(elapsed.asSeconds()*-100,0);
    for (int i=0;i<8;i++)
    {
        if(time>i-0.9*i) robot->setTextureRect(frame[i]);
        if(time>=0.80) time=0;
    }
    if(side!="left")
    {
        robot->setOrigin(robot->getLocalBounds().width/2,0);
        robot->setScale(-0.5,0.5);
        side = "left";
    }
}

void Player::animated(const sf::Time& elapsed)
{
    robot->setTextureRect(sf::IntRect(0, 0, 192, 256));
    time += elapsed.asSeconds();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        run_right(elapsed);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        run_left(elapsed);
    }
}

