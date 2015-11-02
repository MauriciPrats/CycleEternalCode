#pragma once

#include "cocos2d.h"
#include "src/Scenes/BaseScene.h"
#include "src/Gameplay/Train/Train.h"
#include <vector>
class GameScene : public BaseScene
{
public:
	static cocos2d::Scene* createScene();

	CREATE_FUNC(GameScene);

	// Implementation of the keyboard event callback function prototype
	bool onTouchEvent(cocos2d::Touch* touch, cocos2d::Event* event);
	void onMouseEventDown(cocos2d::Event* event);
	void onMouseEventUp(cocos2d::Event* event);

	void processInput(cocos2d::Vec2 position,float deltaTime);
	void update(float deltaTime);
protected:
	std::vector<Train*>* trains;
	void loadSceneElements();
	bool isMousePressedDown;
	cocos2d::Vec2* lastPointPressed;
	float actualDampeningFactor;
	cocos2d::DrawNode* line;
};

