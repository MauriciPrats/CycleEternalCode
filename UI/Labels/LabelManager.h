#pragma once

#include <string>
#include <vector>
#include "src/UI/CustomUIElementConfiguration.h"
#include "cocos2d.h"

class LabelManager
{
public:

	// Returns the instance of LabelManager as a reference
	static LabelManager& getInstance()
	{
		static LabelManager labelManagerInstance; //This is the only instance created (Lazy initialization)
		return labelManagerInstance;
	}

	cocos2d::Label* getLabel(const std::string label_id);

private:

	const std::string LABEL_CONFIG_FILE_PATH = "../res/UILabelsConfig.txt";

	std::map<std::string,CustomUIElementConfiguration*> label_configurations;

	LabelManager();
	LabelManager(LabelManager const&); //This overrides the implicit constructor
	void operator=(LabelManager const&); //This overrides the implicit = operator

};

