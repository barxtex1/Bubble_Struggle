#ifndef WIDGETS_H
#define WIDGETS_H
#pragma once
#include "defs.h"

class Widgets : public sf::Sprite
{
private:
    std::unique_ptr<sf::Texture> textura_time;
    std::unique_ptr<sf::Sprite> czas;
    std::unique_ptr<sf::Texture> textura_life;
    std::unique_ptr<sf::Sprite> zycie;
    std::unique_ptr<sf::Texture> textura_numb;
    std::unique_ptr<sf::Sprite> numbers;
    std::vector<std::unique_ptr<sf::Sprite>> life_;
    sf::Font font_;
    sf::Text text_ects;
    std::vector<sf::IntRect>frame_numb;
    double b = 25.6;
    bool end_time = false;
public:
    Widgets(const float& W, const float& H, const int& n_of_life);
    void Animate_time();
    friend class Scena;
};

#endif // WIDGETS_H
