#include "GameManager.h"


GameManager::GameManager()
{
	gameObjects = new std::vector<GameObject*>();
}

void GameManager::Update(float deltaTime){
	for (int i = 0; i < gameObjects->size(); ++i){
		gameObjects->at(i)->Update(deltaTime);
	}
}

void GameManager::clear(){
	gameObjects->erase(gameObjects->begin(), gameObjects->end());
}

GameManager::~GameManager()
{
}
