#include "GameScene.h"
#include "src/Gameplay/Paths/Path.h"
#include "src/Gameplay/Paths/PathManager.h"
#include "src/Gameplay/Paths/PathsGroup.h"

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
	Path* linePath = PathManager::getInstance().createLinePath(10, 100, 200, 20);
	linePath->linkPathToLayer(this);

	Path* circlePath = PathManager::getInstance().createCirclePath(300, 200, 100);
	circlePath->linkPathToLayer(this);

	PathsGroup* pathsGroup = new PathsGroup(linePath);
	pathsGroup->connectPath(circlePath,linePath->getFirstPathSegment()->getNextPathSegment()->getNextPathSegment(),circlePath->getFirstPathSegment()->getNextPathSegment()->getNextPathSegment());

}