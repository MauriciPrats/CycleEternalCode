#include "Drawable.h"

void Drawable::initialize(cocos2d::Layer* layer, std::string spriteName){
	sprite = cocos2d::Sprite::create(spriteName);
	layer->addChild(sprite);
	this->layer = layer;
}