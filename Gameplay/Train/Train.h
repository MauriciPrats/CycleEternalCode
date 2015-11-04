#pragma once

#include "cocos2d.h"
#include <vector>
#include "src/Gameplay/Train/TrainHead.h"
#include "src/Gameplay/Train/Wagon.h"
#include "src/Gameplay/GameObject.h"


class Train : public GameObject
{
public:
	Train(cocos2d::Layer* layerPutInto,TrainHead* trainHead);
	~Train();

	void Update(float deltaTime);
	void addWagon(cocos2d::Vec2 position);
	void addWagon();
	TrainHead* getTrainHead(){ return trainHead; }

private:
	TrainHead* trainHead;
	std::vector<Wagon*>* wagons;
	cocos2d::Layer* layerPutInto;

};

