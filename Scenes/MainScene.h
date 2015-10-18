#pragma once

#include "cocos2d.h"

class MainScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    //Callbacks
    void menuCloseCallback(cocos2d::Ref* pSender);
	void startGameCallback(cocos2d::Ref* pSender);
	void quitGameCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
	CREATE_FUNC(MainScene);

private:

	void loadSceneElements();
};

