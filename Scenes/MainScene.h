#pragma once

#include "cocos2d.h"
#include "src/Scenes/BaseScene.h"

class MainScene : public BaseScene
{
public:
    static cocos2d::Scene* createScene();

    //Callbacks
    void menuCloseCallback(cocos2d::Ref* pSender);
	void startGameCallback(cocos2d::Ref* pSender);
	void quitGameCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(MainScene);

protected:
	void loadSceneElements();
};

