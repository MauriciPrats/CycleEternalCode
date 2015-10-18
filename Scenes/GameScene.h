#pragma once

#include "cocos2d.h"
#include "src/Scenes/BaseScene.h"

class GameScene : public BaseScene
{
public:
	static cocos2d::Scene* createScene();

	CREATE_FUNC(GameScene);

protected:
	void loadSceneElements();
};

