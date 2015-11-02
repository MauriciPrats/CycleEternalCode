#include "Train.h"
#include "src/Util/Util.h"

USING_NS_CC;

Train::Train(Layer* layer, Vec2 position, bool isTrainLeader, Train* trainLeader)
{
	layerIsPutInto = layer;
	sprite = Sprite::create("MovingTrain.png");
	sprite->setPosition(position);
	layer->addChild(sprite);
	this->position = new Vec2();
	this->position->set(position);
	velocity = new Vec2();
	velocity->set(50, 50);
	this->isTrainLeader = isTrainLeader;
	this->trainLeader = trainLeader;
	timeAccumulatedSincePathDeployed = 0.0f;
}


Train::~Train()
{
	layerIsPutInto->removeChild(sprite);
}

void Train::Update(float deltaTime){
	*position += (deltaTime * *velocity);
	sprite->setPosition(*position);
	//Rotate the sprite
	Vec2 lookTowards = *position + *velocity;
	Util::rotateNodeToPoint(sprite, lookTowards);

	
	if (isTrainLeader ){
		timeAccumulatedSincePathDeployed += deltaTime;
		if (timeAccumulatedSincePathDeployed > 0.15f){
			timeAccumulatedSincePathDeployed = 0.0f;
			Sprite* s = Sprite::create("PathSegment.png");
			s->setPosition(*position);
			layerIsPutInto->addChild(s);
			Util::rotateNodeToPoint(s, lookTowards);
		}
	}


}
