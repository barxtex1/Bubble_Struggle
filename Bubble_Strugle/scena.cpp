#include "scena.h"

Scena::Scena(const int& W,const int& H) : window_(sf::VideoMode(W, H), "Bubble Strugle"),Width(W),Height(H)
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
    tlo.emplace_back(std::move(bkgd01));

    std::unique_ptr<sf::Texture> bg02 = std::make_unique<sf::Texture>();
    if(!bg02->loadFromFile("Source/Universe/bkgd_1.png")){
        throw("Could not load texture");
    }
    bg02->setRepeated(true);
    textury.emplace_back(std::move(bg02));

    std::unique_ptr<sf::Sprite> bkgd02 = std::make_unique<sf::Sprite>();
    bkgd02->setTexture(**(textury.end() - 1));
    bkgd02->setTextureRect(sf::IntRect(0, 0, Width, Height));
    tlo.emplace_back(std::move(bkgd02));

    std::unique_ptr<sf::Texture> bg03 = std::make_unique<sf::Texture>();
    if(!bg03->loadFromFile("Source/Universe/bkgd_5.png")){
        throw("Could not load texture");
    }
    bg03->setRepeated(true);
    textury.emplace_back(std::move(bg03));

    std::unique_ptr<sf::Sprite> bkgd03 = std::make_unique<sf::Sprite>();
    bkgd03->setTexture(**(textury.end() - 1));
    bkgd03->setTextureRect(sf::IntRect(0, 0, Width, Height));
    tlo.emplace_back(std::move(bkgd03));

    std::unique_ptr<sf::Texture> bg04 = std::make_unique<sf::Texture>();
    if(!bg04->loadFromFile("Source/Universe/bkgd_7.png")){
        throw("Could not load texture");
    }
    bg04->setRepeated(true);
    textury.emplace_back(std::move(bg04));

    std::unique_ptr<sf::Sprite> bkgd04 = std::make_unique<sf::Sprite>();
    bkgd04->setTexture(**(textury.end() - 1));
    bkgd04->setTextureRect(sf::IntRect(0, 0, Width, Height));
    tlo.emplace_back(std::move(bkgd04));

    std::unique_ptr<sf::Texture> text_dirt = std::make_unique<sf::Texture>();
    if(!text_dirt->loadFromFile("Source/Rocks/DIRT.png")){
        throw("Could not load texture");
    }
    text_dirt->setRepeated(true);
    textury.emplace_back(std::move(text_dirt));

    std::unique_ptr<sf::Sprite> dirt01 = std::make_unique<sf::Sprite>();
    dirt01->setTexture(**(textury.end() - 1));
    dirt01->setTextureRect(sf::IntRect(0, 0, Width, 200));
    dirt01->setPosition(0,Height-200);
    sciany.emplace_back(std::move(dirt01));
    std::unique_ptr<sf::Sprite> dirt02 = std::make_unique<sf::Sprite>();
    dirt02->setTexture(**(textury.end() - 1));
    dirt02->setTextureRect(sf::IntRect(0, 0, 25, Height));
    dirt02->setPosition(0,0);
    sciany.emplace_back(std::move(dirt02));
    std::unique_ptr<sf::Sprite> dirt03 = std::make_unique<sf::Sprite>();
    dirt03->setTexture(**(textury.end() - 1));
    dirt03->setTextureRect(sf::IntRect(0, 0, 25, Height));
    dirt03->setPosition(Width-25,0);
    sciany.emplace_back(std::move(dirt03));
    std::unique_ptr<sf::Sprite> dirt04 = std::make_unique<sf::Sprite>();
    dirt04->setTexture(**(textury.end() - 1));
    dirt04->setTextureRect(sf::IntRect(0, 0, Width, 25));
    dirt04->setPosition(0,0);
    sciany.emplace_back(std::move(dirt04));
}

int Scena::getWidth()
{
    return Width;
}
int Scena::getHeight()
{
    return Height;
}

void Scena::draw(Player& hero)
{
    window_.clear(sf::Color::Black);

    for(auto& el: tlo)
    {
        window_.draw(*el);
    }
    for(auto& el: sciany)
    {
        window_.draw(*el);
    }
    window_.draw(*hero.robot);
    window_.display();
}

void Scena::loop(Player& hero)
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
    this->draw(hero);
    }
}
