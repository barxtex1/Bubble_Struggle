#include "scena.h"

Scena::Scena(const int& W,const int& H) : Width(W),Height(H)
{
    font.loadFromFile("BAUHS93.ttf");
    text = sf::Text("BRAWO! +1 ECTS",font);
    text_lose = sf::Text("SPROBUJ JESZCZE RAZ!",font);
    text_over = sf::Text("KONIEC GRY!",font);
    text_win = sf::Text("ZALICZYLES! GRATULACJE :)",font);
    text_start = sf::Text("PRZYGOTUJ SIE!",font);
    text.setCharacterSize(50);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color::Red);
    text.setPosition(W/2-(text.getGlobalBounds().width/2),H/2);
    text_lose.setCharacterSize(50);
    text_lose.setStyle(sf::Text::Bold);
    text_lose.setFillColor(sf::Color::Red);
    text_lose.setPosition(W/2-(text_lose.getGlobalBounds().width/2),H/2);
    text_over.setCharacterSize(50);
    text_over.setStyle(sf::Text::Bold);
    text_over.setFillColor(sf::Color::Red);
    text_over.setPosition(W/2-(text_over.getGlobalBounds().width/2),H/2);
    text_win.setCharacterSize(50);
    text_win.setStyle(sf::Text::Bold);
    text_win.setFillColor(sf::Color::Red);
    text_win.setPosition(W/2-(text_win.getGlobalBounds().width/2),H/2);
    text_start.setCharacterSize(50);
    text_start.setStyle(sf::Text::Bold);
    text_start.setFillColor(sf::Color::Red);
    text_start.setPosition(W/2-(text_start.getGlobalBounds().width/2),H/2);

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

int Scena::getNofLife()
{
    return numb_of_life;
}

void Scena::resetLife_Ects()
{
    numb_of_life = 3;
    ECTS = 0;
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
    if(lim>=lim_rozb)
    {
        dodano = true;
    }
}



void Scena::draw(const sf::Time& elp,Player& hero,Weapon* laser,Widgets& wid,sf::RenderWindow& window_)
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

    // Widgets

    window_.draw(*wid.czas);
    if(start_sleep>2)
    {
        if(hero.kolizja_ball!=true && Balls.empty()!=true)
        {
            wid.Animate_time();
        }
    }

    for(auto& l : wid.life_)
    {
        window_.draw(*l);
    }
    window_.draw(wid.text_ects);
    wid.numbers->setTextureRect(wid.frame_numb[ECTS]);
    window_.draw(*wid.numbers);


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
        if(start_sleep>2)
        {
            if(b->kolizja_hero!=true && wid.end_time!=true)
            {
                b->step(elp,getWidth(),getHeight());
            }
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
    if(start_sleep>2)
    {
        if(hero.kolizja_ball!=true && wid.end_time!=true)
        {
            hero.animated(elp,sciany);
        }
        else
        {
            hero.explosion->setPosition(hero.robot->getGlobalBounds().left-40,hero.robot->getGlobalBounds().top);
            window_.draw(*hero.explosion);
            hero.kolizja(elp);
            if(numb_of_life!=0)
            {
                window_.draw(text_lose);
                sleep += elp.asSeconds();
            }
            else
            {
                window_.draw(text_over);
                sleep += elp.asSeconds();
            }

        }
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

    // Sprawdzanie czy gracz wygral czy przegral
    if(Balls.empty())
    {
        if(ECTS!=5)
        {
            window_.draw(text);
            sleep += elp.asSeconds();
        }
        else
        {
            window_.draw(text_win);
            sleep += elp.asSeconds();
        }
    }
    if(wid.end_time)
    {
        if(numb_of_life!=0)
        {
            window_.draw(text_lose);
            sleep += elp.asSeconds();
        }
        else
        {
            window_.draw(text_over);
            sleep += elp.asSeconds();
        }
    }
    if(sleep>2)
    {
        if(Balls.empty())
        {
            wygrana = true;
        }
        if(hero.kolizja_ball || wid.end_time)
        {
            przegrana = true;
            hero.kolizja_ball = false;
            wid.end_time = false;
            numb_of_life--;
            Balls.clear();
        }
    }

    if(start_sleep<2)
    {
        window_.draw(text_start);
        start_sleep +=elp.asSeconds();
    }
    window_.display();
}

void Scena::loop(Player& hero,sf::RenderWindow& window_)
{
    sf::Clock clock;
    Widgets wid(getWidth(),getHeight(),numb_of_life);
    hero.robot->setPosition(getWidth()/2-25,getHeight()-329);
    if(ECTS == 0)
    {
        Balls.emplace_back() = new Enemy(100,100,100,350,100);
        lim_rozb = 250;
    }
    if(ECTS == 1)
    {
        Balls.emplace_back() = new Enemy(100,100,100,350,100);
        Balls.emplace_back() = new Enemy(100,window_.getSize().x-300,100,350,-100);
        lim_rozb = 250;
    }
    if(ECTS == 2)
    {
        for(int i=0;i<8;i++)
        {
            Balls.emplace_back() = new Enemy(20,50+i*40,50+i*40,250,100);
        }
        lim_rozb = 250;
    }
    if(ECTS == 3)
    {
        for(int i=0;i<2;i++)
        {
            Balls.emplace_back() = new Enemy(80,100+i*200,100+i*50,350,150);
        }
        lim_rozb = 250;
    }
    if(ECTS == 4)
    {
        for(int i=0;i<6;i++)
        {
            Balls.emplace_back() = new Enemy(20,50+i*40,50+i*40,250,100);
        }
        for(int i=0;i<6;i++)
        {
            Balls.emplace_back() = new Enemy(20,window_.getSize().x-(150+i*40),75+i*40,250,-100);
        }
        lim_rozb = 250;
    }
    if(ECTS == 5)
    {
        for(int i=0;i<2;i++)
        {
            Balls.emplace_back() = new Enemy(30,50+i*50,50+i*50,600,100);
        }
        for(int i=0;i<2;i++)
        {
            Balls.emplace_back() = new Enemy(30,window_.getSize().x-(100+i*50),50+i*50,600,-100);
        }
        lim_rozb = 550;
    }
    Weapon* laser;
    wygrana = false;
    przegrana = false;
    sleep = 0;
    start_sleep = 0;
    while (window_.isOpen())
    {
        if(wygrana == true)
        {
            ECTS++;
            break;
        }
        if(przegrana == true)
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
                if(fire!=true && wid.end_time!=true && start_sleep>2)
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
        this->draw(elapsed,hero,laser,wid,window_);
    }
}

