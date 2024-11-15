#pragma once
#include "Entity.h"

class ZombieEntity : public Entity
{
public:
    ZombieEntity(float radius, const sf::Color& color) : Entity(radius, color)
    {
    }

    void Update();
};
