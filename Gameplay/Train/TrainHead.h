#pragma once

#include "src/Gameplay/Drawable.h"

class TrainHead : public Drawable
{
public:
	TrainHead(cocos2d::Layer* layer, cocos2d::Vec2 position);
	~TrainHead();

	virtual void Update(float deltaTime);
	const cocos2d::Vec2* getVelocity(){ return velocity; }
	const cocos2d::Vec2* getPosition(){ return position; }
	void setVelocity(cocos2d::Vec2 newVelocity){ velocity->set(newVelocity); }
	cocos2d::Vec2 getStepPosition(int position){ CCLOG("%i", position); return *positionsOfPath->at(position); }
private:
	const float TRAIN_TIME_BETWEEN_SPRITES = 0.15f;
	TrainHead* trainLeader;
	cocos2d::Vec2* position;
	cocos2d::Vec2* velocity;
	std::vector<cocos2d::Sprite*>* spritesPut;
	std::vector<cocos2d::Vec2*>* positionsOfPath;
	float timeAccumulatedSincePathDeployed;
};

