#pragma once

#include "cocos2d.h"
#include "src/Scenes/BaseScene.h"

class LevelSelectScene : public BaseScene
{

public:
	static cocos2d::Scene* createScene();

	//Callbacks
	void backCallback(cocos2d::Ref* pSender);
	void goToLevelCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(LevelSelectScene);
protected:
	void loadSceneElements();
};
