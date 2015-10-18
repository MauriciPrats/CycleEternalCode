#pragma once

#include "cocos2d.h"

class LevelSelectScene : public cocos2d::Layer
{

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	//Callbacks
	void backCallback(cocos2d::Ref* pSender);
	void goToLevelCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(LevelSelectScene);

private:

	void loadSceneElements();
};
