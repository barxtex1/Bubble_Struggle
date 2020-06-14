#include "menu.h"

Menu::Menu(const int& W,const int& H)
{
    font.loadFromFile("BAUHS93.ttf");

    // menu glowne
    text = sf::Text("Rozpocznij gre",font);
    txt.emplace_back(text,false,1);
    text = sf::Text("Sterowanie",font);
    txt.emplace_back(text,false,2);
    text = sf::Text("Zrodla",font);
    txt.emplace_back(text,false,3);
    text = sf::Text("Wyjscie",font);
    txt.emplace_back(text,false,4);
    for(size_t i=0;i<txt.size();i++)
    {
        txt[i].text.setCharacterSize(100);
        txt[i].text.setStyle(sf::Text::Bold);
        txt[i].text.setFillColor(sf::Color::Black);
        txt[i].text.setPosition(W/2-(txt[i].text.getGlobalBounds().width/2),125+i*125);
    }

    // zrodla
    text = sf::Text("Textury:",font);
    zrodl.emplace_back(text);
    text = sf::Text("- https://opengameart.org",font);
    zrodl.emplace_back(text);
    text = sf::Text("- https://kenney.nl/assets/page:2",font);
    zrodl.emplace_back(text);
    text = sf::Text("Gra oparta na podstawie:",font);
    zrodl.emplace_back(text);
    text = sf::Text("https://www.wyspagier.pl/bubble-struggle.htm",font);
    zrodl.emplace_back(text);
    for(size_t i=0;i<zrodl.size();i++)
    {
        zrodl[i].setCharacterSize(40);
        zrodl[i].setFillColor(sf::Color::Black);
        zrodl[i].setOutlineThickness(1);
        zrodl[i].setOutlineColor(sf::Color::White);
        zrodl[i].setPosition(100,125+i*70);
    }

    // sterowanie
    text = sf::Text("Poruszanie sie w lewo",font);
    sterow.emplace_back(text);
    text = sf::Text("Poruszanie sie w prawo",font);
    sterow.emplace_back(text);
    text = sf::Text("Strzal laserem",font);
    sterow.emplace_back(text);
    for(size_t i=0;i<sterow.size()-1;i++)
    {
        sterow[i].setCharacterSize(70);
        sterow[i].setStyle(sf::Text::Bold);
        sterow[i].setOutlineThickness(1);
        sterow[i].setOutlineColor(sf::Color::White);
        sterow[i].setFillColor(sf::Color::Black);
        sterow[i].setPosition(W/2-(sterow[i].getGlobalBounds().width/2)+100,125+i*150);
    }
    sterow[2].setCharacterSize(70);
    sterow[2].setStyle(sf::Text::Bold);
    sterow[2].setOutlineThickness(1);
    sterow[2].setOutlineColor(sf::Color::White);
    sterow[2].setFillColor(sf::Color::Black);
    sterow[2].setPosition(W/2-(sterow[2].getGlobalBounds().width/2)+170,410);


    Powrot = sf::Text("Powrot",font);
    Powrot.setCharacterSize(100);
    Powrot.setStyle(sf::Text::Bold);
    Powrot.setFillColor(sf::Color::Black);
    Powrot.setPosition(100,H-Powrot.getGlobalBounds().height-150);



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

    // sterowanie
    textura_sterow = std::make_unique<sf::Texture>();
    if(!textura_sterow->loadFromFile("Source/Numbers/Keyboard.png")){
        throw("Could not load texture");
    }
    ster = std::make_unique<sf::Sprite>(*textura_sterow);
    ster->setTextureRect(sf::IntRect(155,90, 32, 40));
    ster->setScale(4,4);
    ster->setPosition(88,60);
    sprite_sterow.emplace_back(std::move(ster));
    ster = std::make_unique<sf::Sprite>(*textura_sterow);
    ster->setTextureRect(sf::IntRect(220,90, 32, 40));
    ster->setScale(4,4);
    ster->setPosition(100,210);
    sprite_sterow.emplace_back(std::move(ster));
    ster = std::make_unique<sf::Sprite>(*textura_sterow);
    ster->setTextureRect(sf::IntRect(95,30, 162, 27));
    ster->setScale(2,3.5);
    ster->setPosition(100,410);
    sprite_sterow.emplace_back(std::move(ster));

}

void Menu::select(const sf::Event& event,sf::RenderWindow& window_)
{
    sf::Vector2f mouse_position = window_.mapPixelToCoords(sf::Mouse::getPosition(window_));
    for(auto& el: txt)
    {
        if(el.text.getGlobalBounds().contains(mouse_position))
        {
            el.text.setOutlineThickness(5);
            el.text.setOutlineColor(sf::Color::White);
        }
        else
        {
            el.text.setOutlineThickness(0);
        }
    }
    if(Powrot.getGlobalBounds().contains(mouse_position))
    {
        Powrot.setOutlineThickness(5);
        Powrot.setOutlineColor(sf::Color::White);
    }
    else
    {
        Powrot.setOutlineThickness(0);
    }


    if (event.type == sf::Event::MouseButtonPressed)
    {
        if(event.mouseButton.button == sf::Mouse::Left)
        {
            if(t2!=true && t3!=true)
            {
                for(auto& el: txt)
                {
                    if(el.text.getGlobalBounds().contains(mouse_position))
                    {
                        sl = true;
                        el.slct = true;
                    }
                }
            }
            if(Powrot.getGlobalBounds().contains(mouse_position))
            {
                t2 = false;
                t3 = false;
            }
        }
    }
}

void Menu::CheckSelect()
{
    for(auto& el: txt)
    {
        if(el.slct==true)
        {
            if(el.nr==1)
            {
                sl = false;
                el.slct = false;
                t1 = true;
            }
            if(el.nr==2)
            {
                sl = false;
                el.slct = false;
                t2 = true;
            }
            if(el.nr==3)
            {
                sl = false;
                el.slct = false;
                t3 = true;
            }
            if(el.nr==4)
            {
                sl = false;
                el.slct = false;
                t4 = true;
            }
        }
    }

}

void Menu::draw(sf::RenderWindow& window_)
{
    window_.clear(sf::Color::Black);
    window_.draw(*tlo);
    window_.draw(*robot);
    if(t2!=true && t3!=true)
    {
        for(auto& el: txt)
        {
            window_.draw(el.text);
        }
    }
    else if(t2)
    {
        for(auto& s: sprite_sterow)
        {
            window_.draw(*s);
        }
        for(auto& t : sterow)
        {
            window_.draw(t);
        }
        window_.draw(Powrot);
    }
    else if(t3)
    {
        for(auto& el: zrodl)
        {
            window_.draw(el);
        }
        window_.draw(Powrot);
    }
    window_.display();
}


void Menu::loop(sf::RenderWindow& window_)
{
    while (window_.isOpen())
    {
        if(sl)
        {
            CheckSelect();
        }
        if(t1)
        {
            t1 = false;
            break;
        }
        if(t4)
        {
            t4 = false;
            window_.close();
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
