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

bool GameScene::onTouchEvent(Touch* touch, Event* event){
	cocos2d::Vec2 pos = Director::sharedDirector()->convertToGL(touch->getLocationInView());
	processInput(pos);
	return false;
}

void GameScene::onMouseEvent(Event* event){
	EventMouse* e = (EventMouse*)event;
	cocos2d::Vec2 pos = cocos2d::Vec2(e->getCursorX(), e->getCursorY());
	processInput(pos);
}

void  GameScene::processInput(cocos2d::Vec2 position){
	PathSegment* closestPathSegment = pathsGroup->getLastInsertedPath()->getPathSegmentClosestToPoint(position.x, position.y);

	cocos2d::Vec2 closestPathPosition = cocos2d::Vec2(closestPathSegment->getPositionX(), closestPathSegment->getPositionY());
	float distance = closestPathPosition.distance(position);

	Path* circlePath = PathManager::getInstance().createCirclePath(position.x, position.y, distance);
	circlePath->linkPathToLayer(this);

	pathsGroup->connectPath(circlePath,position);
}

void GameScene::loadSceneElements(){
	Path* circlePath = PathManager::getInstance().createCirclePath(300, 200, 100);
	circlePath->linkPathToLayer(this);

	pathsGroup = new PathsGroup(circlePath);
	
	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchEvent, this);

	auto listener2 = EventListenerMouse::create();
	listener2->onMouseDown = CC_CALLBACK_1(GameScene::onMouseEvent, this);
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener2, this);
}