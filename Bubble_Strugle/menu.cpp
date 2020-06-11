#include "menu.h"

Menu::Menu(const int& W,const int& H)
{
    font.loadFromFile("BAUHS93.ttf");
    text_rozp = sf::Text("Rozpocznij gre",font);
    texty.emplace_back(text_rozp);
    text_sterow = sf::Text("Sterowanie",font);
    texty.emplace_back(text_sterow);
    text_zrodl = sf::Text("Zrodla",font);
    texty.emplace_back(text_zrodl);
    text_wyjsc = sf::Text("Wyjscie",font);
    texty.emplace_back(text_wyjsc);

    for(size_t i=0;i<texty.size();i++)
    {
        texty[i].setCharacterSize(100);
        texty[i].setStyle(sf::Text::Bold);
        texty[i].setFillColor(sf::Color::Black);
        texty[i].setPosition(W/2-(texty[i].getGlobalBounds().width/2),125+i*125);
    }

    textura = std::make_unique<sf::Texture>();
    if(!textura->loadFromFile("Source/Rocks/DIRT.png")){
        throw("Could not load texture");
    }
    textura->setRepeated(true);
    tlo = std::make_unique<sf::Sprite>();
    tlo->setTexture(*textura);
    tlo->setTextureRect(sf::IntRect(0, 0, W, H));

    // add robot
    textura_robot = std::make_unique<sf::Texture>();
    if(!textura_robot->loadFromFile("Source/Robot/PNG/Poses HD/character_robot_wide.png")){
        throw("Could not load texture");
    }
    robot = std::make_unique<sf::Sprite>();
    robot->setTexture(*textura_robot);
    robot->setScale(1.5,1.5);
    robot->setPosition(W-robot->getGlobalBounds().width-50,H-robot->getGlobalBounds().height);

}

void Menu::select(const sf::Event& event,sf::RenderWindow& window_)
{
    sf::Vector2f mouse_position = window_.mapPixelToCoords(sf::Mouse::getPosition(window_));
    for(auto& el: texty)
    {
        if(el.getGlobalBounds().contains(mouse_position))
        {
            el.setOutlineThickness(5);
            el.setOutlineColor(sf::Color::White);
        }
        else
        {
            el.setOutlineThickness(0);
        }
    }

    if (event.type == sf::Event::MouseButtonPressed)
    {
        if(event.mouseButton.button == sf::Mouse::Left)
        {
            for(auto& el: texty)
            {
                if(el.getGlobalBounds().contains(mouse_position))
                {
                    slct = true;
                    if(std::find(texty.begin(),texty.end(),el)!=texty.end())
                    {
                        std::cerr<<"Gowno"<<std::endl;
                    }
                }
            }
        }
    }
}


void Menu::draw(sf::RenderWindow& window_)
{
    window_.clear(sf::Color::Black);
    window_.draw(*tlo);
    window_.draw(*robot);
    for(auto& el: texty)
    {
        window_.draw(el);
    }
    window_.display();
}


void Menu::loop(sf::RenderWindow& window_)
{

    while (window_.isOpen())
    {
        if(slct)
        {
//            break;
        }
        sf::Event event;
        while (window_.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window_.close();
            }
            select(event,window_);
        }
        sf::sleep(sf::milliseconds(1));
        this->draw(window_);
    }
}
