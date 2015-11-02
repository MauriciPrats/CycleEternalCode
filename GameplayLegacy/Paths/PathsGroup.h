#pragma once

#include <vector>
#include "src/GameplayLegacy/Paths/Path.h"

class PathsGroup
{
public:

	PathsGroup(Path* firstPath);
	~PathsGroup();
	void connectPath(Path* newPath, cocos2d::Vec2 positionSelected);
	Path* getLastInsertedPath() const { return lastPath; }
private:
	void connectCircleToLine(Path* newPath,cocos2d::Vec2 positionSelected);
	void connectLineToCircle(Path* newPath, cocos2d::Vec2 positionSelected);
	void connectCircleToCircle(Path* newPath, cocos2d::Vec2 positionSelected);
	std::vector<Path*>* paths;
	Path* lastPath;

};

