#pragma once

#include<string>

//Interface to generate TextObjects
class TextObject
{
public:

	//Virtual method to convert text into an object to be retrieved from a file
	virtual TextObject* fromText(std::string text) = 0;
};

