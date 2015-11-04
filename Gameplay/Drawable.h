#pragma once

#include "cocos2d.h"

class Drawable
{
public:

	void initialize(cocos2d::Layer* layer,std::string spriteName);
	virtual void Update(float deltaTime) = 0;
	//virtual ~GameObject();
protected:
	cocos2d::Sprite* sprite;
	cocos2d::Layer* layer;
};

