#include "TextParser.h"
#include "src/Util/Util.h"
#include <functional>

std::vector<TextObject*> TextParser::TextToVector(std::string text, TextObject* classType){
	//Split the text into the multiple elements of the class
	std::vector<std::string> classTexts = Util::split(text, TEXT_PARSER_VECTOR_SEPARATOR_TOKEN);
	std::vector<TextObject*> parsedObjects;
	for (int i = 0; i < classTexts.size(); ++i){	
		//For each element we convert it to a new class
		parsedObjects.push_back(TextToClass(classTexts[i], classType));
	}
	return parsedObjects;
}

TextObject* TextParser::TextToClass(std::string text, TextObject* classType){
	TextObject* newTextObjectCreated = classType->fromText(text);
	return newTextObjectCreated;
}

