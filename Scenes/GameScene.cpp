#include "GameScene.h"
#include "src/Gameplay/Paths/Path.h"
#include "src/Gameplay/Paths/PathManager.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

void GameScene::loadSceneElements(){
	Path* path = PathManager::createLinePath(10, 100, 200, 20);
}