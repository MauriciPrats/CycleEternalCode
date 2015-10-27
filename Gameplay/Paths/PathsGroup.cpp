#include "PathsGroup.h"


PathsGroup::PathsGroup(Path* firstPath)
{
	paths = new std::vector<Path*>();
	paths->push_back(firstPath);
	lastPath = firstPath;
}

void PathsGroup::connectPath(Path* newPath, PathSegment* segmentOldPath, PathSegment* segmentNewPath){
	paths->push_back(newPath);
	lastPath->connectSegments(segmentOldPath, segmentNewPath);
	newPath->setFirstPathSegment(segmentNewPath);
	lastPath = newPath;
}

PathsGroup::~PathsGroup()
{
}
