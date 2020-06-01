#ifndef WEAPON_H
#define WEAPON_H
#pragma once
#include "defs.h"

class Weapon : public sf::Sprite
{
private:
    float a=1;
    bool fire_l = false;
    std::unique_ptr<sf::Texture> textura_wep;
    std::unique_ptr<sf::Sprite> laser_;
public:
    Weapon(const float& x, const float& y);
    ~Weapon();
    friend class Scena;
    void Animate();
};

#endif // WEAPON_H
