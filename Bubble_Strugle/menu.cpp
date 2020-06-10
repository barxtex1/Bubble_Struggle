#include "menu.h"

Menu::Menu(const int& W,const int& H) : window_(sf::VideoMode(W, H), "Bubble Strugle")
{
    font.loadFromFile("arial.ttf");
    text_start = sf::Text("Rozpocznij gre",font);
    text_start.setCharacterSize(100);
    text_start.setStyle(sf::Text::Bold);
    text_start.setFillColor(sf::Color::Red);
    text_start.setPosition(W/2-(text_start.getGlobalBounds().width/2),200);
}

void Menu::draw()
{
    window_.clear(sf::Color::Black);
    window_.draw(text_start);

    window_.display();
}


void Menu::loop()
{
    while (window_.isOpen())
    {
        sf::Event event;
        while (window_.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window_.close();
            }
        }
        sf::sleep(sf::milliseconds(1));
        this->draw();
    }
}
