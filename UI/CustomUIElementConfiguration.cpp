#include "CustomUIElementConfiguration.h"
#include "src/Util/TextSerialization/TextParser.h"
#include "src/Util/Util.h"
#include<vector>

CustomUIElementConfiguration::CustomUIElementConfiguration()
{
	//Set default values of the variables
	text_id = "";
	text = "Default";
	text_size = 10;
	x_position = 0;
	y_position = 0;
	anchor = AnchorPoint::Center;
	normal_background = "";
}


CustomUIElementConfiguration::~CustomUIElementConfiguration()
{
}

TextObject* CustomUIElementConfiguration::fromText(std::string text){
	CustomUIElementConfiguration* objectToReturn = getNewInstance();
	std::vector<std::string> parsedAttributes = Util::split(text,TextParser::TEXT_PARSER_ATRIBUTE_SEPARATOR_TOKEN);
	for (int i = 0; i < parsedAttributes.size(); ++i){
		std::string attribute;
		std::string value;
		std::vector<std::string> nameAndValue = Util::split(parsedAttributes[i], TextParser::TEXT_PARSER_NAME_VALUE_SEPARATOR_TOKEN);
		attribute = Util::trim(nameAndValue[0]);
		value = Util::trim(nameAndValue[1]);

		setAttribute(attribute, value, objectToReturn);
	}
	return objectToReturn;
}

void CustomUIElementConfiguration::setAttribute(std::string attribute, std::string value, CustomUIElementConfiguration* objectToReturn){
	if (attribute == "text_id"){
		objectToReturn->setTextId(value);
	}
	else if (attribute == "x_position"){
		objectToReturn->setXPosition(std::stof(value));
	}
	else if (attribute == "y_position"){
		objectToReturn->setYPosition(std::stof(value));
	}
	else if (attribute == "anchor"){
		AnchorPoint new_anchor_point;
		new_anchor_point = (AnchorPoint)std::stoi(value);
		objectToReturn->setAnchor(new_anchor_point);
	}
	else if (attribute == "text"){
		objectToReturn->setText(value);
	}
	else if (attribute == "text_size"){
		objectToReturn->setTextSize(std::stoi(value));
	}
	else if (attribute == "normal_background"){
		objectToReturn->setNormalBackground(value);
	}
}

const cocos2d::Vec2 const CustomUIElementConfiguration::getAnchoredPosition(float element_width,float element_height){
	cocos2d::Vec2* anchor_result = new cocos2d::Vec2();

	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	if (anchor == AnchorPoint::Center){ 
		anchor_result->x = (visibleSize.width / 2) + x_position + origin.x;
		anchor_result->y = (visibleSize.height / 2) + y_position + origin.y;
		return *anchor_result;
	}
	else if (anchor == AnchorPoint::BottomLeft){ 
		anchor_result->x = x_position + (element_width/2) + origin.x;
		anchor_result->y = y_position +(element_height/2)+ origin.y;
		return *anchor_result;
	}
	else if (anchor == AnchorPoint::BottomRight){
		anchor_result->x = visibleSize.width - (element_width/2) - x_position + origin.x;
		anchor_result->y = y_position + origin.y +(element_height/2);
		return *anchor_result;
	}
	else if (anchor == AnchorPoint::TopLeft){
		anchor_result->x = x_position + (element_width/2) + origin.x;
		anchor_result->y = visibleSize.height - (element_height/2) - y_position + origin.y;
		return *anchor_result;
	}
	else if (anchor == AnchorPoint::TopRight){
		anchor_result->x = visibleSize.width - (element_width/2) - x_position + origin.x;
		anchor_result->y = visibleSize.height - (element_height/2) - y_position + origin.y;
		return *anchor_result;
	}
	else{
		return NULL;
	}
}
