#include "scena.h"

Scena::Scena(const int& Width,const int& Height) : window_(sf::VideoMode(Width, Height), "Bubble Strugle")
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    sf::Texture bg01;
    if(!bg01.loadFromFile("../Universe/bkgd_0.png")){
        throw("Could not load texture");
    }
    bg01.setRepeated(true);
    sf::Sprite bkgd01;
    bkgd01.setTexture(bg01);
    bkgd01.setTextureRect(sf::IntRect(0, 0, 800, 600));
    plansza.emplace_back(bkgd01);
}

void Scena::draw()
{
    window_.clear(sf::Color::Black);
    // draw everything here...

    for(auto& el: plansza)
    {
        window_.draw(el);
    }

    // end the current frame
    window_.display();
}

void Scena::loop()
{
    while (window_.isOpen())
    {
        std::cerr<<"Otwarte"<<std::endl;
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
