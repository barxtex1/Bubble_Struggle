#ifndef SCENA_H
#define SCENA_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <vector>
#include <cmath>

class Scena
{
private:
    sf::RenderWindow window_;
    std::vector<sf::Sprite> obiekty;
    std::vector<std::unique_ptr<sf::Sprite>> plansza;
    std::vector<std::unique_ptr<sf::Texture>> textury;
public:
    Scena(const int& Width,const int& Height);
    void add_obiekt();
    void add_gift();
    void draw();
    void loop();
};

#endif // SCENA_H
