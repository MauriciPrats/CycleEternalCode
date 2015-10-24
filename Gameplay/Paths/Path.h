#pragma once

#include "src/Gameplay/Paths/PathSegment.h"
#include <vector>
#include <map>

class Path
{
public:

	Path(PathSegment* firstSegment);
	~Path();

	void connectSegments(PathSegment segmentToConnect, Path firstSegmentNewPath);

private:

	PathSegment* firstPathSegment;
	std::map<long,PathSegment*>* pathSegments;

	//Function to recalculate all the pathSegments, returns the segments no longer in the path
	std::map<long, PathSegment*>* recalculatePathSegments();
	void clearSegments(std::map<long,PathSegment*>* segmentsToClear);
};

