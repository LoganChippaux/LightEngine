#include "DummyEntity.h"

#include <iostream>

void DummyEntity::OnCollision(Entity* other)
{
	std::cout << "DummyEntity::OnCollision" << std::endl;
}

void DummyEntity::Shoot(Entity* other)
{
	std::cout << "je me tire" << std::endl;
}