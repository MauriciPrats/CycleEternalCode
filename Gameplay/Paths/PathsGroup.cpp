#include "PathsGroup.h"


PathsGroup::PathsGroup(Path* firstPath)
{
	paths = new std::vector<Path*>();
	paths->push_back(firstPath);
	lastPath = firstPath;
}

void PathsGroup::connectPath(Path* newPath,cocos2d::Vec2 selectedPosition){
	PathSegment* closestPathSegment = getLastInsertedPath()->getPathSegmentClosestToPoint(selectedPosition.x, selectedPosition.y);

	cocos2d::Vec2 closestPathPosition = cocos2d::Vec2(closestPathSegment->getPositionX(), closestPathSegment->getPositionY());
	float distance = closestPathPosition.distance(selectedPosition);

	PathSegment* closestSegmentNewPath = newPath->getPathSegmentClosestToPoint(closestPathPosition.x, closestPathPosition.y);

	paths->push_back(newPath);
	lastPath->connectSegments(closestPathSegment, closestSegmentNewPath);
	newPath->setFirstPathSegment(closestSegmentNewPath);
	lastPath = newPath;
}

PathsGroup::~PathsGroup()
{
}
