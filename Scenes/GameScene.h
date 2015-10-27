#pragma once

#include "cocos2d.h"
#include "src/Scenes/BaseScene.h"
#include "src/Gameplay/Paths/PathsGroup.h"

class GameScene : public BaseScene
{
public:
	static cocos2d::Scene* createScene();

	CREATE_FUNC(GameScene);

	// Implementation of the keyboard event callback function prototype
	bool onTouchEvent(cocos2d::Touch* touch, cocos2d::Event* event);
	void onMouseEvent(cocos2d::Event* event);
	void processInput(cocos2d::Vec2 position);
protected:
	void loadSceneElements();
	PathsGroup* pathsGroup;
};

