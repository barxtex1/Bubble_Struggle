#include "widgets.h"

Widgets::Widgets(const float& W, const float& H, const int& n_of_life)
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
    for(int i=0;i<n_of_life;i++)
    {
        zycie = std::make_unique<sf::Sprite>();
        zycie->setTexture(*textura_life);
        zycie->setScale(0.8,0.8);
        zycie->setPosition(25+i*zycie->getGlobalBounds().width+i*10,H-zycie->getGlobalBounds().height-25);
        life_.emplace_back(std::move(zycie));
    }

    // add licznik ECTS
    font_.loadFromFile("arial.ttf");
    text_ects = sf::Text("Liczba zdobytych ECTS: ",font_);
    text_ects.setCharacterSize(50);
    text_ects.setStyle(sf::Text::Bold);
    text_ects.setFillColor(sf::Color::Black);
    text_ects.setPosition(W-text_ects.getGlobalBounds().width-100,H-text_ects.getGlobalBounds().height-50);

    //add numbers
    textura_numb = std::make_unique<sf::Texture>();
    if(!textura_numb->loadFromFile("Source/Numbers/sheet.png")){
        throw("Could not load texture");
    }
    numbers = std::make_unique<sf::Sprite>();
    numbers->setTexture(*textura_numb);
    numbers->setPosition(W-100,H-115);
    numbers->setScale(2,2);
    frame_numb.emplace_back(sf::IntRect(0,0, 35, 50));   // 0
    frame_numb.emplace_back(sf::IntRect(35,0, 23, 50));  // 1
    frame_numb.emplace_back(sf::IntRect(56,0, 32, 50));  // 2
    frame_numb.emplace_back(sf::IntRect(88,0, 30, 50));  // 3
    frame_numb.emplace_back(sf::IntRect(118,0, 37, 50)); // 4
    frame_numb.emplace_back(sf::IntRect(155,0, 32, 50)); // 5

}

void Widgets::Animate_time()
{
    if(czas->getGlobalBounds().width>1)
    {
        czas->setScale(3,b);
    }
    else
    {
        end_time = true;
    }
    b -= 0.004;
}

