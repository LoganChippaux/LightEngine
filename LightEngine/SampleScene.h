#pragma once

#include "Scene.h"

class DummyEntity;

class SampleScene : public Scene
{
	DummyEntity* pEntity1;
	DummyEntity* pEntity2;
	DummyEntity* pEntity3;
	DummyEntity* pEntity4;
	DummyEntity* pEntity5;
	DummyEntity* pEntity6;

	DummyEntity* pEntitySelected;

private:
	void TrySetSelectedEntity(DummyEntity* pEntity, int x, int y);

public:
	void Initialize() override;
	void HandleInput(const sf::Event& event) override;
	void Update() override;
};


