#include "scena.h"

Scena::Scena(const int& W,const int& H) : window_(sf::VideoMode(W, H), "Bubble Strugle"),Width(W),Height(H)
{
    font.loadFromFile("arial.ttf");
    text = sf::Text("CONGRATULATIONS!",font);
    text.setCharacterSize(50);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color::Red);
    text.setPosition(W/2-(text.getGlobalBounds().width/2),H/2);
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

int Scena::getECTS()
{
    return ECTS;
}


void Scena::Kolizja_B_H(Player& hero)
{
    for(auto& ball : Balls)
    {
        if(sqrt(pow((hero.robot->getGlobalBounds().left+hero.robot->getGlobalBounds().width/2)-(ball->getGlobalBounds().left+ball->getGlobalBounds().width/2),2)
                +pow((hero.robot->getGlobalBounds().top+hero.robot->getGlobalBounds().height/2)-(ball->getGlobalBounds().top+ball->getGlobalBounds().height/2),2))
                <ball->getRadius()+20)
        {
            ball->kolizja_hero = true;
            hero.kolizja_ball = true;
        }
    }
}

void Scena::Kolizja_B_W(Weapon* laser)
{
    for(auto& ball : Balls)
    {
        if(sqrt(pow((laser->laser_->getGlobalBounds().left+laser->laser_->getGlobalBounds().width/2)-(ball->getGlobalBounds().left+ball->getGlobalBounds().width/2),2)
                +pow((laser->laser_->getGlobalBounds().top+laser->laser_->getGlobalBounds().height/2)-(ball->getGlobalBounds().top+ball->getGlobalBounds().height/2),2))
                <ball->getRadius()+25)
        {
            laser->kolizja_ball = true;
            ball->kolizja_laser = true;
        }
        if(sqrt(pow((laser->laser_->getGlobalBounds().left+laser->laser_->getGlobalBounds().width/2)-(ball->getGlobalBounds().left+ball->getGlobalBounds().width/2),2)
                +pow((laser->laser_->getGlobalBounds().top)-(ball->getGlobalBounds().top+ball->getGlobalBounds().height/2),2))
                <ball->getRadius()-25)
        {
            laser->kolizja_ball = true;
            ball->kolizja_laser = true;
        }
        if(sqrt(pow((laser->laser_->getGlobalBounds().left+laser->laser_->getGlobalBounds().width/2)-(ball->getGlobalBounds().left+ball->getGlobalBounds().width/2),2)
                +pow((laser->laser_->getGlobalBounds().top+laser->laser_->getGlobalBounds().height)-(ball->getGlobalBounds().top+ball->getGlobalBounds().height/2),2))
                <ball->getRadius())
        {
            laser->kolizja_ball = true;
            ball->kolizja_laser = true;
        }
    }
}

void Scena::rozbicie(Enemy* b)
{
    b->kolizja_laser = false;
    radius = b->getRadius()/2;
    x = b->getGlobalBounds().left+b->getGlobalBounds().width/2;
    y = b->getGlobalBounds().top+b->getGlobalBounds().height/2-radius;
    V_x = std::abs(b->getVelocity_x());
    lim = b->getLimit()-50;
    auto it = std::find(Balls.begin(),Balls.end(),b);
    Balls.erase(it);
    if(lim>=250)
    {
        dodano = true;
    }
}



void Scena::draw(const sf::Time& elp,Player& hero,Weapon* laser)
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

    //Sprawdzanie czy wystepuje kolizja
    Kolizja_B_H(hero);
    if(fire)
    {
        Kolizja_B_W(laser);
    }

    //animacja pilki i rozbicie na dwie mniejsze
    for(auto& b : Balls)
    {
        window_.draw(*b);
        if(b->kolizja_laser==true)
        {
            rozbicie(b);
        }
        if(b->kolizja_hero!=true)
        {
            b->step(elp,getWidth(),getHeight());
        }
    }
    if(dodano==true)
    {
        Balls.emplace_back() = new Enemy(radius,x-2*radius,y,lim,-std::abs(V_x));
        Balls.emplace_back() = new Enemy(radius,x,y,lim,V_x);
        dodano = false;
    }

    // animacja hero i wybuch przy kolizji z pilka
    window_.draw(*hero.robot);
    if(hero.kolizja_ball!=true)
    {
        hero.animated(elp,sciany);
    }
    else
    {
        hero.explosion->setPosition(hero.robot->getGlobalBounds().left-40,hero.robot->getGlobalBounds().top);
        window_.draw(*hero.explosion);
        hero.kolizja(elp);
    }

    // animacja lasera oraz kolizja ze sciana i pilka
    if(fire==true)
    {
        window_.draw(*laser->laser_);
        if(laser->fire_l==true)
        {
            laser->Animate();
            if(laser->kolizja_ball==true)
            {
                fire = false;
                laser->fire_l = false;
                laser->a = 1;
                laser->kolizja_ball = false;
                delete laser;
            }
        }
        else
        {
            fire = false;
            laser->a = 1;
            delete laser;
        }
    }

    // Sprawdzanie czy gracz wygral
    if(Balls.empty())
    {
        window_.draw(text);
        ECTS++;
        wygrana = true;
    }
    window_.display();
}

void Scena::loop(Player& hero)
{
    sf::Clock clock;
    if(ECTS == 0)
    {
        Balls.emplace_back() = new Enemy(100,100,100,350,100);
    }
    if(ECTS == 1)
    {
        Balls.emplace_back() = new Enemy(100,100,100,350,100);
        Balls.emplace_back() = new Enemy(100,window_.getSize().x-300,100,350,-100);
    }
    Weapon* laser;
    wygrana = false;
    while (window_.isOpen())
    {
        if(wygrana == true)
        {
            break;
        }
        sf::Event event;
        while (window_.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window_.close();
            }
            if (event.type == sf::Event::KeyReleased)
            {
                if(fire!=true)
                {
                    if (event.key.code == sf::Keyboard::Space)
                    {
                        laser = new Weapon(hero.robot->getGlobalBounds().left+hero.robot->getGlobalBounds().width/2-5,hero.robot->getGlobalBounds().top+hero.robot->getGlobalBounds().height/2);
                        fire = true;
                        laser->fire_l = true;
                    }
                }
            }
        }
        sf::Time elapsed = clock.restart();
        sf::sleep(sf::milliseconds(1));        
        this->draw(elapsed,hero,laser);
    }
}

