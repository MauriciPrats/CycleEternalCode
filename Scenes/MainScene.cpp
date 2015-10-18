#include "MainScene.h"
#include "src/UI/Buttons/ButtonManager.h"
#include "src/UI/Labels/LabelManager.h"
#include "src/Scenes/LevelSelectScene.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = MainScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}


void MainScene::loadSceneElements(){

	//Menu Items
	auto startButton = ButtonManager::getInstance().getButton("start_game_main_menu", CC_CALLBACK_1(MainScene::startGameCallback, this));
	auto quitButton = ButtonManager::getInstance().getButton("quit_game_main_menu", CC_CALLBACK_1(MainScene::quitGameCallback, this));

	//Menu
	auto menu = Menu::create(startButton, quitButton, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	//Labels
	auto titleLabel = LabelManager::getInstance().getLabel("id_title_main_menu");
	this->addChild(titleLabel, 1);

}


//Callbacks
void MainScene::startGameCallback(Ref* pSender)
{

	Scene* levelSelectScene = LevelSelectScene::createScene();
	goToScene(levelSelectScene);
}

void MainScene::quitGameCallback(Ref* pSender)
{
	Director::getInstance()->end();

	#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		exit(0);
	#endif

}
