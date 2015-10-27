#pragma once

#include <vector>
#include "src/Gameplay/Paths/Path.h"

class PathsGroup
{
public:

	PathsGroup(Path* firstPath);
	~PathsGroup();
	void connectPath(Path* newPath, PathSegment* segmentOldPath, PathSegment* segmentNewPath);
	Path* getLastInsertedPath() const { return lastPath; }
private:
	std::vector<Path*>* paths;
	Path* lastPath;

};

