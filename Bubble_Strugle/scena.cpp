#include "scena.h"

Scena::Scena(const int& Width,const int& Height) : window_(sf::VideoMode(Width, Height), "Bubble Strugle")
{
    std::unique_ptr<sf::Texture> bg01 = std::make_unique<sf::Texture>();
    if(!bg01->loadFromFile("Source/Universe/bkgd_0.png")){
        throw("Could not load texture");
    }
    bg01->setRepeated(true);
    textury.emplace_back(std::move(bg01));

    std::unique_ptr<sf::Sprite> bkgd01 = std::make_unique<sf::Sprite>();
    bkgd01->setTexture(**(textury.end() - 1));
    bkgd01->setTextureRect(sf::IntRect(0, 0, Width, Height));
    plansza.emplace_back(std::move(bkgd01));

    std::unique_ptr<sf::Texture> bg02 = std::make_unique<sf::Texture>();
    if(!bg02->loadFromFile("Source/Universe/bkgd_1.png")){
        throw("Could not load texture");
    }
    bg02->setRepeated(true);
    textury.emplace_back(std::move(bg02));

    std::unique_ptr<sf::Sprite> bkgd02 = std::make_unique<sf::Sprite>();
    bkgd02->setTexture(**(textury.end() - 1));
    bkgd02->setTextureRect(sf::IntRect(0, 0, Width, Height));
    plansza.emplace_back(std::move(bkgd02));

    std::unique_ptr<sf::Texture> bg03 = std::make_unique<sf::Texture>();
    if(!bg03->loadFromFile("Source/Universe/bkgd_5.png")){
        throw("Could not load texture");
    }
    bg03->setRepeated(true);
    textury.emplace_back(std::move(bg03));

    std::unique_ptr<sf::Sprite> bkgd03 = std::make_unique<sf::Sprite>();
    bkgd03->setTexture(**(textury.end() - 1));
    bkgd03->setTextureRect(sf::IntRect(0, 0, Width, Height));
    plansza.emplace_back(std::move(bkgd03));

    std::unique_ptr<sf::Texture> bg04 = std::make_unique<sf::Texture>();
    if(!bg04->loadFromFile("Source/Universe/bkgd_7.png")){
        throw("Could not load texture");
    }
    bg04->setRepeated(true);
    textury.emplace_back(std::move(bg04));

    std::unique_ptr<sf::Sprite> bkgd04 = std::make_unique<sf::Sprite>();
    bkgd04->setTexture(**(textury.end() - 1));
    bkgd04->setTextureRect(sf::IntRect(0, 0, Width, Height));
    plansza.emplace_back(std::move(bkgd04));
}

void Scena::draw()
{
    window_.clear(sf::Color::Black);
    // draw everything here...

    for(auto& el: plansza)
    {
        window_.draw(*el);
    }

    // end the current frame
    window_.display();
}

void Scena::loop()
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
