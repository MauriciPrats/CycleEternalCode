#include "LevelSelectScene.h"
#include "src/UI/Buttons/ButtonManager.h"
#include "src/UI/Labels/LabelManager.h"
#include "src/Scenes/MainScene.h"
#include "src/Scenes/GameScene.h"

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
	Scene* mainMenuScene = MainScene::createScene();
	// Transition Fade
	goToScene(mainMenuScene);

}

void LevelSelectScene::goToLevelCallback(Ref* pSender)
{
	//TEMPORAL: Goes to the Game scene, it will have to change when de level picker is implemented
	Scene* gameScene = GameScene::createScene();
	goToScene(gameScene);

}


