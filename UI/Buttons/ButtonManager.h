#pragma once

#include <string>
#include <vector>
#include "src/UI/Buttons/CustomButtonConfiguration.h"
#include "cocos2d.h"

class ButtonManager
{
public:

	// Returns the instance of ButtonManager as a reference
	static ButtonManager& getInstance()
	{
		static ButtonManager buttonManagerInstance; //This is the only instance created (Lazy initialization)
		return buttonManagerInstance;
	}

	cocos2d::MenuItem* getButton(const std::string button_id, const cocos2d::ccMenuCallback& callback);
	
private:

	const std::string BUTTON_CONFIG_FILE_PATH = "../res/UIButtonsConfig.txt";

	std::map<std::string, CustomButtonConfiguration*> button_configurations;

	ButtonManager();
	ButtonManager(ButtonManager const&); //This overrides the implicit constructor
	void operator=(ButtonManager const&); //This overrides the implicit = operator

	
};

