#pragma once

#include<string>
#include<vector>
#include "TextObject.h"

static class TextParser
{
public:

	const static char TEXT_PARSER_VECTOR_SEPARATOR_TOKEN = '|';
	const static char TEXT_PARSER_ATRIBUTE_SEPARATOR_TOKEN= ',';
	const static char TEXT_PARSER_NAME_VALUE_SEPARATOR_TOKEN = ':';

	static std::vector<TextObject*> TextToVector(std::string Text, TextObject* classType);
	static TextObject* TextToClass(std::string Text, TextObject* classType);


};

