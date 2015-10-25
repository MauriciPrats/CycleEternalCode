#include "CustomButtonConfiguration.h"
#include "cocos2d.h"


CustomButtonConfiguration::CustomButtonConfiguration() : CustomUIElementConfiguration()
{
	selected_background = "";
}


CustomButtonConfiguration::~CustomButtonConfiguration()
{
}

void CustomButtonConfiguration::setAttribute(std::string attribute, std::string value, CustomUIElementConfiguration* objectToReturn){
	//New attributes
	if (attribute == "selected_background"){
		((CustomButtonConfiguration*) objectToReturn)->setSelectedBackground(value);
	}
	else{
		//if it's none of the new attributes we call the base class
		CustomUIElementConfiguration::setAttribute(attribute, value, objectToReturn);
	}
}
