#include "ZombieEntity.h"
#include "GameManager.h" 

#include <cmath>

void ZombieEntity::Update()
{
    float speed = 50.f;
    float deltaTime = GameManager::Get()->GetDeltaTime();
    SetPosition(GetPosition().x - speed * deltaTime, GetPosition().y);
}
