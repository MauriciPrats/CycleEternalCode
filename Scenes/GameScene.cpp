#include "GameScene.h"
#include "src/Gameplay/Train/Train.h"

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
	Vec2 pos = Director::sharedDirector()->convertToGL(touch->getLocationInView());
	lastPointPressed = new Vec2(pos.x, pos.y);
	isMousePressedDown = true;
	return false;
}

void GameScene::onMouseEventDown(Event* event){
	EventMouse* e = (EventMouse*)event;
	lastPointPressed = new cocos2d::Vec2(e->getCursorX(), e->getCursorY());
	isMousePressedDown = true;
	actualDampeningFactor = 0.0f;
	line->setVisible(true);
}

void GameScene::onMouseEventUp(Event* event){
	isMousePressedDown = false;
	line->setVisible(false);
}

void  GameScene::processInput(cocos2d::Vec2 position,float deltaTime){
	
	//Attraction
	for (int i = 0; i < trains->size(); ++i){
		float speed = trains->at(i)->getVelocity()->getLength();
		Vec2 attractionDirection = position - *trains->at(i)->getPosition();
		Vec2 originalVelocity = *trains->at(i)->getVelocity();
		line->clear();
		line->drawLine(*trains->at(i)->getPosition(), position, cocos2d::Color4F(1, 0, 0, 1));
		Vec2 orbitDirection = attractionDirection.rotateByAngle(Vec2::ZERO, M_PI / 2);
		float attractionDirectionSymbol = 1.0f;
		if (Vec2::angle(originalVelocity, orbitDirection) >(M_PI / 2)){
			attractionDirectionSymbol = -1.0f;
		}
		float timeToGetFullRotation = 1.0f;
		actualDampeningFactor += deltaTime * (1.0/timeToGetFullRotation);
		if (actualDampeningFactor > 1.0f){ actualDampeningFactor = 1.0f; }
		
		Vec2 velocity = (orbitDirection.getNormalized() * attractionDirectionSymbol * actualDampeningFactor) + trains->at(i)->getVelocity()->getNormalized();
		if (abs(Vec2::angle(velocity, attractionDirection)) < abs(Vec2::angle(originalVelocity, attractionDirection))){
			trains->at(i)->setVelocity(velocity.getNormalized()*speed);
		}
		else{
			CCLOG("%f", abs(Vec2::angle(velocity, attractionDirection)));
			CCLOG("%f", abs(Vec2::angle(originalVelocity, attractionDirection)));
			CCLOG("-----");
		}
	}
}

void GameScene::loadSceneElements(){
	line = DrawNode::create();
	this->addChild(line);
	trains = new std::vector<Train*>();
	isMousePressedDown = false;
	actualDampeningFactor = 0.0f;
	Train* train = new Train(this, Vec2(100,200),true,nullptr);
	trains->push_back(train);

	schedule(schedule_selector(GameScene::update));

	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchEvent, this);

	auto listener2 = EventListenerMouse::create();
	listener2->onMouseDown = CC_CALLBACK_1(GameScene::onMouseEventDown, this);
	listener2->onMouseUp = CC_CALLBACK_1(GameScene::onMouseEventUp, this);

	//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener2, this);
}

void GameScene::update(float deltaTime){
	if (isMousePressedDown){
		processInput(*lastPointPressed,deltaTime);
	}

	for (int i = 0; i < trains->size(); ++i){
		trains->at(i)->Update(deltaTime);
	}
}