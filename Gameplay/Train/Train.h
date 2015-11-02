#pragma once

#include "cocos2d.h"


class Train
{
public:
	Train(cocos2d::Layer* layer,cocos2d::Vec2 position,bool isTrainLeader,Train* trainLeader);
	~Train();

	void Update(float deltaTime);
	const cocos2d::Vec2* getVelocity(){ return velocity; }
	const cocos2d::Vec2* getPosition(){ return position; }
	void setVelocity(cocos2d::Vec2 newVelocity){ velocity->set(newVelocity); }
private:
	 cocos2d::Layer* layerIsPutInto;
	 cocos2d::Sprite* sprite;
	 bool isTrainLeader;
	 Train* trainLeader;
	 cocos2d::Vec2* position;
	 cocos2d::Vec2* velocity;

	 float timeAccumulatedSincePathDeployed;
};

