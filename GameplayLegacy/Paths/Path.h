#pragma once

#include "src/GameplayLegacy/Paths/PathSegment.h"
#include <vector>
#include <map>

class Path
{
public:

	typedef enum PathType{Circle = 0, Line = 1};

	Path(long idPath,PathType pathType,PathSegment* firstSegment);
	~Path();

	void connectSegments(PathSegment* segmentToConnect, PathSegment* segmentNewPath);
	void linkPathToLayer(cocos2d::Layer* layer);
	void unlinkPathToLayer(cocos2d::Layer* layer);
	void setFirstPathSegment(PathSegment* pathSegment);
	void recalculatePathSegments();
	void invertPathDirection();
	PathType getPathType(){ return pathType; }
	PathSegment* getFirstPathSegment(){ return firstPathSegment; }
	PathSegment* getPathSegmentClosestToPoint(float x_position, float y_position);

private:
	long idPath;
	PathType pathType;
	PathSegment* firstPathSegment;
	std::map<long,PathSegment*>* pathSegments;

	//Function to recalculate all the pathSegments, returns the segments no longer in the path
	void clearSegments(std::map<long,PathSegment*>* segmentsToClear);
	PathSegment* getLastPathSegment();
};

