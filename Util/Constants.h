#pragma once
class Constants
{
public:
	// Returns the instance of Constants as a reference
	static Constants& getInstance()
	{
		static Constants constantsInstance; //This is the only instance created (Lazy initialization)
		return constantsInstance;
	}

	//All the constants:
	const float PATH_SEGMENT_SIZE = 20.0f;

private:

	Constants(){}
	Constants(Constants const&); //This overrides the implicit constructor
	void operator=(Constants const&); //This overrides the implicit = operator
};

