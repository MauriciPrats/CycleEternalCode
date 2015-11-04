#include "TrainHead.h"
#include "src/Util/Util.h"

USING_NS_CC;

TrainHead::TrainHead(cocos2d::Layer* layer, cocos2d::Vec2 position)
{
	initialize(layer, "MovingTrain.png");

	this->position = new Vec2();
	this->position->set(position);
	velocity = new Vec2();
	velocity->set(50, 50); //PLACEHOLDER
	timeAccumulatedSincePathDeployed = 0.0f;
	spritesPut = new std::vector<Sprite*>();
	positionsOfPath = new std::vector<cocos2d::Vec2*>();
}


TrainHead::~TrainHead()
{
}

void TrainHead::Update(float deltaTime){
	*position += (deltaTime * *velocity);
	sprite->setPosition(*position);
	//Rotate the sprite
	Vec2 lookTowards = *position + *velocity;
	Util::rotateNodeToPoint(sprite, lookTowards);
	Vec2* stepPosition = new Vec2();
	stepPosition->set(*position);
	positionsOfPath->push_back(stepPosition);
	timeAccumulatedSincePathDeployed += deltaTime;
	if (timeAccumulatedSincePathDeployed > TRAIN_TIME_BETWEEN_SPRITES){
		timeAccumulatedSincePathDeployed = 0.0f;
		Sprite* s = Sprite::create("PathSegment.png");
		s->setPosition(*position);
		layer->addChild(s);
		spritesPut->push_back(s);
		Util::rotateNodeToPoint(s, lookTowards);
	}
}