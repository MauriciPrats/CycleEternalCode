#include "PathSegment.h"
#include "cocos2d.h"
#include "src/Util/Util.h"

PathSegment::PathSegment(long idPath,long idPathSegment, float position_x, float position_y, bool directionlastToNext)
{
	this->idPath = idPath;
	this->idPathSegment = idPathSegment;
	this->position_x = position_x;
	this->position_y = position_y;
	this->directionLastToNext = directionlastToNext;
	lastSegment = nullptr;
	nextSegment = nullptr;
	sprite = nullptr;
	layer = nullptr;
}

PathSegment::~PathSegment()
{
	lastSegment = nullptr;
	nextSegment = nullptr;
	if (layer != nullptr && sprite != nullptr){
		layer->removeChild(sprite);
	}
}

const bool PathSegment::hasNext() const {
	 if (directionLastToNext){ return nextSegment != nullptr; } 
	 else{ return lastSegment != nullptr; }
}


void PathSegment::getPathDirection(cocos2d::Vec2& result) const{
	cocos2d::Vec2 direction = cocos2d::Vec2(0, 0);
	cocos2d::Vec2 position = cocos2d::Vec2(position_x, position_y);
	
	if (lastSegment != nullptr){
		cocos2d::Vec2 lastPosition = cocos2d::Vec2(lastSegment->getPositionX(), lastSegment->getPositionY());
		if (directionLastToNext){
			direction = direction + (position - lastPosition);
		}
		else{
			direction = direction + (lastPosition - position);
		}
	}

	if (nextSegment != nullptr){
		cocos2d::Vec2 nextPosition = cocos2d::Vec2(nextSegment->getPositionX(), nextSegment->getPositionY());
		if (directionLastToNext){
			direction = direction + (nextPosition - position);
		}
		else{
			direction = direction + (position - nextPosition);
		}
	}

	result.x = direction.x;
	result.y = direction.y;
}

void PathSegment::linkToLayer(cocos2d::Layer* layer){
	if (sprite == nullptr){
		sprite = cocos2d::Sprite::create("PathSegment.png");
	}
	cocos2d::Vec2 position = cocos2d::Vec2(position_x, position_y);
	sprite->setPosition(position);

	//Set the rotation looking towards the next node
	cocos2d::Vec2 direction = cocos2d::Vec2();
	getPathDirection(direction);

	cocos2d::Vec2 lookingPosition = position + direction;

	Util::rotateNodeToPoint(sprite, lookingPosition);
	
	layer->addChild(sprite);
	this->layer = layer;
}

void PathSegment::removeFromLayer(cocos2d::Layer* layer){
	if (sprite != nullptr){
		layer->removeChild(sprite);
		this->layer = nullptr;
	}
}
