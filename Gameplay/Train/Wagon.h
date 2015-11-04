#pragma once

#include "src/Gameplay/Drawable.h"
#include "src/Gameplay/Train/TrainHead.h"

class Wagon : public Drawable
{
public:
	Wagon(cocos2d::Layer* layer,cocos2d::Vec2 position, TrainHead* trainLeader);
	~Wagon();

	virtual void Update(float deltaTime);

private:
	const float WAGON_TIME_BETWEEN_SPRITES = 0.15f;
	TrainHead* trainLeader;
	std::vector<cocos2d::Sprite*>* spritesPut;
	cocos2d::Vec2* position;
	int indexNextPath;
	cocos2d::Vec2* lastPosition;
	float timeAccumulatedSincePathDeployed;
};

