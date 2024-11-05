#include "GameManager.h"

#include "Entity.h"
#include "Debug.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>

GameManager::GameManager()
{
	mpWindow = nullptr;
	mDeltaTime = 0.0f;
	mpScene = nullptr;
	mWindowWidth = -1;
	mWindowHeight = -1;
}

GameManager* GameManager::Get()
{
	static GameManager* mInstance = new GameManager();

	return mInstance;
}

GameManager::~GameManager()
{
	delete mpWindow;
	delete mpScene;

	for (Entity* entity : mEntities)
	{
		delete entity;
	}
}

void GameManager::CreateWindow(unsigned int width, unsigned int height, const char* title, int fpsLimit)
{
	_ASSERT(mpWindow == nullptr);

	mpWindow = new sf::RenderWindow(sf::VideoMode(width, height), title);
	mpWindow->setFramerateLimit(fpsLimit);

	mWindowWidth = width;
	mWindowHeight = height;
}

void GameManager::Run()
{
	if (mpWindow == nullptr) 
	{
		std::cout << "Window not created, creating default window" << std::endl;
		CreateWindow(1280, 720, "Default window");
	}

	sf::Font font;
	bool fontLoaded = font.loadFromFile("Hack-Regular.ttf");
	_ASSERT(fontLoaded);

	_ASSERT(mpScene != nullptr);

	sf::Clock clock;
	while (mpWindow->isOpen())
	{
		SetDeltaTime(clock.restart().asSeconds());

		sf::Event event;
		while (mpWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				mpWindow->close();
			}

			mpScene->HandleInput(event);
		}

		Update();
		Draw();
	}
}

void GameManager::Update()
{
	mpScene->Update();

    //Update
    for (auto it = mEntities.begin(); it != mEntities.end(); )
    {
		Entity* entity = *it;

        entity->Update();

        if (entity->ToDestroy() == false)
        {
            ++it;
            continue;
        }

        mEntitiesToDestroy.push_back(entity);
        it = mEntities.erase(it);
    }

    //Collision
    for (auto it1 = mEntities.begin(); it1 != mEntities.end(); ++it1)
    {
        auto it2 = it1;
        ++it2;
        for (; it2 != mEntities.end(); ++it2)
        {
            Entity* entity = *it1;
            Entity* otherEntity = *it2;

            if (entity->IsColliding(otherEntity))
            {
                entity->OnCollision(otherEntity);
                otherEntity->OnCollision(entity);
            }
        }
    }

	for (auto it = mEntitiesToDestroy.begin(); it != mEntitiesToDestroy.end(); ++it) 
	{
		delete* it;
	}

    mEntitiesToDestroy.clear();
}

void GameManager::Draw()
{
	mpWindow->clear();
	
	for (Entity* entity : mEntities)
	{
		mpWindow->draw(*entity->GetShape());
	}
	
	std::vector<Line>& lines = Debug::GetLines();
	for (Line& line : lines)
	{
		sf::Vertex vertices[2] = { line.start, line.end };
		mpWindow->draw(vertices, 2, sf::Lines);
	}

	Debug::ClearLines();

	mpWindow->display();
}

void GameManager::SetDeltaTime(float deltaTime)
{
	mDeltaTime = deltaTime;
}

float GameManager::GetDeltaTime() const
{
	return mDeltaTime;
}

Scene* GameManager::GetScene() const
{
	return mpScene;
}

sf::RenderWindow* GameManager::GetWindow() const
{
	return mpWindow;
}

void Scene::SetGameManager(GameManager* pGameManager) 
{
	mpGameManager = pGameManager;
}

int Scene::GetWindowWidth() const
{
	return mpGameManager->mWindowWidth;
}

int Scene::GetWindowHeight() const
{
	return mpGameManager->mWindowHeight;
}