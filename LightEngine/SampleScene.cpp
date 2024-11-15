#include "SampleScene.h"
#include "DummyEntity.h"
#include "ZombieEntity.h"
#include "Debug.h"

#include <conio.h>
#include <iostream>
#include <cstdlib> 

void SampleScene::Initialize()
{

    pEntity1 = CreateEntity<DummyEntity>(60, sf::Color::Red);
    pEntity1->SetPosition(110, 200);

    pEntity2 = CreateEntity<DummyEntity>(60, sf::Color::Red);
    pEntity2->SetPosition(300, 300);


    pZombie1 = CreateEntity<ZombieEntity>(40, sf::Color::Green);
    pZombie1->SetPosition(800, 200);

    pEntitySelected = nullptr;
}

void SampleScene::HandleInput(const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Button::Right)
        {
            TrySetSelectedEntity(pEntity1, event.mouseButton.x, event.mouseButton.y);
            TrySetSelectedEntity(pEntity2, event.mouseButton.x, event.mouseButton.y);
        }

        if (event.mouseButton.button == sf::Mouse::Button::Left)
        {
            if (pEntitySelected != nullptr)
            {
                pEntitySelected->GoToPosition(event.mouseButton.x, event.mouseButton.y, 100.f);
            }
        }
    }

    if (_kbhit())
    {
        char key = _getch();
        if (key == 's') 
        {
            if (pEntitySelected != nullptr)
            {
                pEntitySelected->Shoot(pZombie1);
            }
        }

        if (key == 'z') 
        {
            auto newZombie = CreateEntity<ZombieEntity>(40, sf::Color::Green);
            newZombie->SetPosition(800, rand() % 600); 
        }
    }
}

void SampleScene::TrySetSelectedEntity(DummyEntity* pEntity, int x, int y)
{
    if (pEntity->IsInside(x, y))
    {
        pEntitySelected = pEntity; 
    }
}

void SampleScene::Update()
{
    if (pEntitySelected != nullptr)
    {
        sf::Vector2f position = pEntitySelected->GetPosition(0.5f, 0.5f);
        Debug::DrawCircle(position.x, position.y, 10, sf::Color::Blue);
    }
}
