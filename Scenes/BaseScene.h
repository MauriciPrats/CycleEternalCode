#pragma once

#include "cocos2d.h"

class BaseScene : public cocos2d::Layer
{
public:
	bool init();

protected:
	virtual void loadSceneElements() = 0;
	void goToScene(cocos2d::Scene* scene);
};

