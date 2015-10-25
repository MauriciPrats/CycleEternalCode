#pragma once

#include "src/Gameplay/Paths/PathSegment.h"
#include <vector>
#include <map>

class Path
{
public:

	Path(long idPath,PathSegment* firstSegment);
	~Path();

	void connectSegments(PathSegment* segmentToConnect, PathSegment* segmentNewPath);
	void linkPathToLayer(cocos2d::Layer* layer);
	void unlinkPathToLayer(cocos2d::Layer* layer);
	void setFirstPathSegment(PathSegment* pathSegment);
	PathSegment* getFirstPathSegment(){ return firstPathSegment; }
	void recalculatePathSegments();

private:

	long idPath;
	PathSegment* firstPathSegment;
	std::map<long,PathSegment*>* pathSegments;

	//Function to recalculate all the pathSegments, returns the segments no longer in the path
	void clearSegments(std::map<long,PathSegment*>* segmentsToClear);
};

