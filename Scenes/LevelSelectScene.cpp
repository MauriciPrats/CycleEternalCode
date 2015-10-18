#include "LevelSelectScene.h"
#include "src/UI/Buttons/ButtonManager.h"
#include "src/UI/Labels/LabelManager.h"
#include "src/Scenes/MainScene.h"

USING_NS_CC;

Scene* LevelSelectScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = LevelSelectScene::create();

	// add layer as a child to scene
	scene->addChild(layer);


	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool LevelSelectScene::init()
{
	//Super init first
	if (!Layer::init()){ return false; }

	loadSceneElements();

	return true;
}

void LevelSelectScene::loadSceneElements(){

	//Menu Items
	auto level1Button = ButtonManager::getInstance().getButton("level_1_button", CC_CALLBACK_1(LevelSelectScene::goToLevelCallback, this));
	auto backButton = ButtonManager::getInstance().getButton("back_button", CC_CALLBACK_1(LevelSelectScene::backCallback, this));

	//Menu
	auto menu = Menu::create(level1Button, backButton, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	//Labels
	auto titleLabel = LabelManager::getInstance().getLabel("id_title_level_select");
	this->addChild(titleLabel, 1);

}


//Callbacks
void LevelSelectScene::backCallback(Ref* pSender)
{
	Scene* levelSelectScene = MainScene::createScene();
	// Transition Fade
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, levelSelectScene, Color3B(0, 0, 0)));

}

void LevelSelectScene::goToLevelCallback(Ref* pSender)
{


}


