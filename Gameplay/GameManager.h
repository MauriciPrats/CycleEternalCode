#pragma once

#include "src/Gameplay/GameObject.h"
#include <vector>
class GameManager
{
public:
	// Returns the instance of GameManager as a reference
	static GameManager& getInstance()
	{
		static GameManager gameManagerInstance; //This is the only instance created (Lazy initialization)
		return gameManagerInstance;
	}

	void Update(float deltaTime);
	void clear();
	void registerGameObject(GameObject* go){ gameObjects->push_back(go); }

private:
	//attributes
	std::vector<GameObject*>* gameObjects;

	//functions
	GameManager();
	~GameManager();
	GameManager(GameManager const&); //This overrides the implicit constructor
	void operator=(GameManager const&); //This overrides the implicit = operator
};

