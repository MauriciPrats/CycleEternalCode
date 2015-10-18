#include "LabelManager.h"
#include "src/Util/TextSerialization/TextParser.h"
#include <CCFileUtils.h>
#include "cocos2d.h";


LabelManager::LabelManager()
{
	//Load the data of all the buttons
	CustomUIElementConfiguration* dummy = new CustomUIElementConfiguration();
	std::string result = cocos2d::FileUtils::sharedFileUtils()->getStringFromFile(LABEL_CONFIG_FILE_PATH);
	std::vector<TextObject*> elements = TextParser::TextToVector(result, dummy);
	for (int i = 0; i < elements.size(); ++i){
		CustomUIElementConfiguration* element = ((CustomUIElementConfiguration*)elements[i]);
		label_configurations[element->getTextId()] = element;
	}

	delete dummy;

	CCLOG("%i labels loaded", label_configurations.size());

}

cocos2d::Label* LabelManager::getLabel(const std::string label_id){
	CustomUIElementConfiguration* customUIElementConfiguration;
	if (label_configurations[label_id] != NULL){
		customUIElementConfiguration = label_configurations[label_id];
	}
	else{
		customUIElementConfiguration = new CustomUIElementConfiguration();
	}

	cocos2d::Label* label = cocos2d::Label::createWithTTF(customUIElementConfiguration->getText(), "fonts/Marker Felt.ttf", customUIElementConfiguration->getTextSize());
	label->setPosition(customUIElementConfiguration->getAnchoredPosition(label->getContentSize().width, label->getContentSize().height));
	return label;
}