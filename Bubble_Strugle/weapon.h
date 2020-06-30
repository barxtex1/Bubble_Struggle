#ifndef WEAPON_H
#define WEAPON_H
#pragma once
#include "defs.h"

class Weapon : public sf::Sprite
{
private:
    bool fire_l = false;
    bool kolizja_ball = false;
    float time_wep = 0;
    std::unique_ptr<sf::Texture> textura_wep;
    std::unique_ptr<sf::Sprite> laser_;
public:
    Weapon(const float& x, const float& y);
    friend class Scena;
    void Animate(const sf::Time& elapsed);
};

#endif // WEAPON_H
