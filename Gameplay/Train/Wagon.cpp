#include "Wagon.h"
#include "src/Util/Util.h"

Wagon::Wagon(cocos2d::Layer* layer, cocos2d::Vec2 position, TrainHead* trainLeader)
{
	initialize(layer, "MovingTrain.png");
	this->trainLeader = trainLeader;
	indexNextPath = 0;
	lastPosition = new cocos2d::Vec2();
	lastPosition->set(position);
	timeAccumulatedSincePathDeployed = 0.0f;
	this->position = new cocos2d::Vec2();
	this->position->set(position);
}


void Wagon::Update(float deltaTime){
	position->set(trainLeader->getStepPosition(indexNextPath));
	indexNextPath++;
	sprite->setPosition(*position);
	cocos2d::Vec2 positionGoingTo = trainLeader->getStepPosition(indexNextPath);
	Util::rotateNodeToPoint(sprite, positionGoingTo);
}
