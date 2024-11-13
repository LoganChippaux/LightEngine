#include "SampleScene.h"

#include "DummyEntity.h"

#include "Debug.h"

#include <conio.h>

#include <iostream>

void SampleScene::Initialize()
{
	pEntity1 = CreateEntity<DummyEntity>(60, sf::Color::Red);
	pEntity1->SetPosition(110, 200);

	pEntity2 = CreateEntity<DummyEntity>(60, sf::Color::Green);
	pEntity2->SetPosition(90, 200);

	pEntity3 = CreateEntity<DummyEntity>(60, sf::Color::Green);
	pEntity3->SetPosition(70, 200);

	pEntity4 = CreateEntity<DummyEntity>(60, sf::Color::Green);
	pEntity4->SetPosition(300, 200);

	pEntity5 = CreateEntity<DummyEntity>(60, sf::Color::Red);
	pEntity5->SetPosition(200, 200);

	pEntity6 = CreateEntity<DummyEntity>(60, sf::Color::Red);
	pEntity6->SetPosition(600, 200);

	pEntitySelected = nullptr;
}

void SampleScene::HandleInput(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed)
		return;

	if (event.mouseButton.button == sf::Mouse::Button::Right)
	{
		TrySetSelectedEntity(pEntity1, event.mouseButton.x, event.mouseButton.y);
		TrySetSelectedEntity(pEntity2, event.mouseButton.x, event.mouseButton.y);
		TrySetSelectedEntity(pEntity3, event.mouseButton.x, event.mouseButton.y);
		TrySetSelectedEntity(pEntity4, event.mouseButton.x, event.mouseButton.y);
		TrySetSelectedEntity(pEntity5, event.mouseButton.x, event.mouseButton.y);
		TrySetSelectedEntity(pEntity6, event.mouseButton.x, event.mouseButton.y);
	}

	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		if (pEntitySelected != nullptr)
		{
			pEntitySelected->GoToPosition(event.mouseButton.x, event.mouseButton.y, 100.f);
		}
	}

	if (_kbhit()) {
		char key = _getch();
		if (key == 'q') {
			std::cout << "bim";
		}
	}
}

void SampleScene::TrySetSelectedEntity(DummyEntity* pEntity, int x, int y)
{
	if (pEntity->IsInside(x, y) == false)
		return;

	pEntitySelected = pEntity;
}

void SampleScene::Update()
{
	if(pEntitySelected != nullptr)
	{
		sf::Vector2f position = pEntitySelected->GetPosition(0.5f, 0.5f);
		Debug::DrawCircle(position.x, position.y, 10, sf::Color::Blue);
	}
}