#include "Train.h"
#include "src/Util/Util.h"

USING_NS_CC;

Train::Train(Layer* layerPutInto,TrainHead* trainHead)
{
	this->trainHead = trainHead;
	wagons = new std::vector<Wagon*>();
	this->layerPutInto = layerPutInto;
}

Train::~Train()
{

}

void Train::Update(float deltaTime){
	trainHead->Update(deltaTime);
	for (int i = 0; i < wagons->size(); ++i){
		wagons->at(i)->Update(deltaTime);
	}
}

void Train::addWagon(cocos2d::Vec2 position){
	Wagon* newWagon = new Wagon(layerPutInto, position, trainHead);
	wagons->push_back(newWagon);
}

void Train::addWagon(){
	addWagon(trainHead->getStepPosition(0));
}