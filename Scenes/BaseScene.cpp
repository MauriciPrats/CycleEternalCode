#include "BaseScene.h"

USING_NS_CC;


void BaseScene::goToScene(cocos2d::Scene* scene){
	// Transition Fade
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene, Color3B(0, 0, 0)));
}

bool BaseScene::init(){
	//Super init first
	if (!Layer::init()){ return false; }
	loadSceneElements();

	return true;
}
