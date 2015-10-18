#pragma once

#include <string>
#include "src/Util/TextSerialization/TextObject.h"
#include "cocos2d.h"
class CustomUIElementConfiguration : public TextObject
{
public:
	typedef enum AnchorPoint{ Center = 0, TopLeft = 1,TopRight = 2,BottomLeft = 3,BottomRight = 4};
	CustomUIElementConfiguration();
	virtual ~CustomUIElementConfiguration();

	TextObject* fromText(std::string text);
	const std::string getTextId() { return text_id; }
	const std::string getText() { return text; }
	const int getTextSize() { return text_size; }
	const float getXPosition() { return x_position; }
	const float getYPosition() { return y_position; }
	const AnchorPoint getAnchor() { return anchor; }
	const cocos2d::Vec2 getAnchoredPosition(){ return getAnchoredPosition(0, 0); }
	const cocos2d::Vec2 getAnchoredPosition(float element_width,float element_height);
	const std::string getNormalBackground(){ return normal_background; }
	const bool hasBackground() { return normal_background != ""; }
	const bool hasText() { return text != "" && text != "Default"; }

	virtual void setAttribute(std::string attribute, std::string value, CustomUIElementConfiguration* objectToReturn);
	virtual CustomUIElementConfiguration* getNewInstance(){ return new CustomUIElementConfiguration(); }

	void setTextId(std::string new_text_id){ text_id = new_text_id; }
	void setText(std::string new_text){ text = new_text; }
	void setTextSize(int new_text_size){ text_size = new_text_size; }
	void setXPosition(float new_x_position){ x_position = new_x_position; }
	void setYPosition(float new_y_position){ y_position = new_y_position; }
	void setAnchor(AnchorPoint new_anchor){ anchor = new_anchor; }
	void setNormalBackground(std::string new_normal_background){ normal_background = new_normal_background; }
	
	
protected:
	std::string text_id;
	std::string text;
	int text_size;
	float x_position;
	float y_position;
	AnchorPoint anchor;
	std::string normal_background;
};

