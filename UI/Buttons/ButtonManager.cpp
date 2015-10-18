#include "ButtonManager.h"
#include "src/Util/TextSerialization/TextParser.h"
#include <CCFileUtils.h>
#include "cocos2d.h";


ButtonManager::ButtonManager()
{
	//Load the data of all the buttons into a map
	CustomButtonConfiguration* dummy = new CustomButtonConfiguration();
	std::string result = cocos2d::FileUtils::sharedFileUtils()->getStringFromFile(BUTTON_CONFIG_FILE_PATH);
	std::vector<TextObject*> elements = TextParser::TextToVector(result, dummy);
	for (int i = 0; i < elements.size(); ++i){
		CustomButtonConfiguration* element = ((CustomButtonConfiguration*)elements[i]);
		button_configurations[element->getTextId()] = element;
	}

	delete dummy;

	CCLOG("%i buttons loaded",button_configurations.size());

}

cocos2d::MenuItem* ButtonManager::getButton(const std::string button_id, const cocos2d::ccMenuCallback& callback){
	CustomButtonConfiguration* customButtonConfiguration;
	if (button_configurations[button_id] != NULL){
		customButtonConfiguration = button_configurations[button_id];
	}
	else{
		customButtonConfiguration = new CustomButtonConfiguration();
	}

	cocos2d::MenuItem* button;
	
	cocos2d::Label* label = cocos2d::Label::createWithTTF(customButtonConfiguration->getText(), "fonts/Marker Felt.ttf", customButtonConfiguration->getTextSize());

	if (customButtonConfiguration->hasBackground()){
		button = cocos2d::MenuItemImage::create(
			customButtonConfiguration->getNormalBackground(),
			customButtonConfiguration->getSelectedBackground(),
			callback);

		if (customButtonConfiguration->hasText()){
			button->addChild(label);
			label->setPosition(cocos2d::Vec2(button->getContentSize().width / 2, button->getContentSize().height / 2));
		}
	}
	else{
		button = cocos2d::MenuItemLabel::create(label,callback);
	}
	
	button->setPosition(customButtonConfiguration->getAnchoredPosition(button->getContentSize().width, button->getContentSize().height));

	
	return button;

}


