#include "player.h"

Player::Player()
{
    //add robot
    textura = std::make_unique<sf::Texture>();
    if(!textura->loadFromFile("Source/Robot/Tilesheet/character_robot_sheetHD.png")){
        throw("Could not load texture");
    }
    robot = std::make_unique<sf::Sprite>();
    robot->setTexture(*textura);
    robot->setTextureRect(sf::IntRect(0, 0, 192, 256));
    robot->setOrigin(robot->getLocalBounds().width/2,0);
    robot->setScale(0.5,0.5);
    for (int i = 0;i<=1344;i+=192)
    {
        frame.emplace_back(sf::IntRect(i,1024, 192, 256));
    }
    //add explosion
    textura_exp = std::make_unique<sf::Texture>();
    if(!textura_exp->loadFromFile("Source/Robot/Explosion/Explosion.png")){
        throw("Could not load texture");
    }
    explosion = std::make_unique<sf::Sprite>();
    explosion->setTexture(*textura_exp);
    explosion->setScale(2,2);
    for (int i = 0;i<=1152;i+=96)
    {
        frame_exp.emplace_back(sf::IntRect(i,0, 96, 96));
    }
    explosion->setTextureRect(frame_exp[0]);
}

void Player::run_right(const sf::Time& elapsed)
{
    robot->move(elapsed.asSeconds()*200,0);
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
    robot->move(elapsed.asSeconds()*-200,0);
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

void Player::animated(const sf::Time& elapsed,const std::vector<std::unique_ptr<sf::Sprite>> &sciany)
{
    robot->setTextureRect(sf::IntRect(0,0, 192, 256));
    time += elapsed.asSeconds();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        run_right(elapsed);
        for (auto &s : sciany)
        {
            if (s->getGlobalBounds().intersects(robot->getGlobalBounds()))
            {
                robot->move(-200*elapsed.asSeconds(),0);
            }
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        run_left(elapsed);
        for (auto &s : sciany)
        {
            if (s->getGlobalBounds().intersects(robot->getGlobalBounds()))
            {
                robot->move(200*elapsed.asSeconds(),0);
            }
        }
    }
}

void Player::kolizja(const sf::Time& elapsed)
{
    time += elapsed.asSeconds();
    for (int i=0;i<12;i++)
    {
        if(time>i-0.9*i) explosion->setTextureRect(frame_exp[i]);
        if(time>=1.2) time=0;
    }
}


