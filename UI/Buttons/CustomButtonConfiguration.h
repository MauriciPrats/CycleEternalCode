#pragma once
#include "src\UI\CustomUIElementConfiguration.h"
#include <string>
class CustomButtonConfiguration :
	public CustomUIElementConfiguration
{

public:

	CustomButtonConfiguration();
	~CustomButtonConfiguration();

	const std::string getSelectedBackground(){ return selected_background; }

	virtual void setAttribute(std::string attribute, std::string value, CustomUIElementConfiguration* objectToReturn);
	virtual CustomUIElementConfiguration* getNewInstance(){ return new CustomButtonConfiguration(); }

	void setSelectedBackground(std::string new_selected_background){ selected_background = new_selected_background; }

protected:
	std::string selected_background;


};

