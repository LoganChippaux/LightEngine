#include "DummyEntity.h"
#include <iostream>

void DummyEntity::OnCollision(Entity* other)
{
    std::cout << "DummyEntity::OnCollision" << std::endl;
}

void DummyEntity::Shoot(Entity* other)
{
    std::cout << "Jessaye de tirer" << std::endl;
    if (other == nullptr)
    {
        std::cout << "Aucune cible trouv�e pour tirer !" << std::endl;
        return;
    }


    std::cout << "Plante tire sur Zombie !" << std::endl;


    if (IsInside(other->GetPosition().x, other->GetPosition().y))
    {
        other->Destroy();
        std::cout << "Zombie d�truit !" << std::endl;
    }
}
