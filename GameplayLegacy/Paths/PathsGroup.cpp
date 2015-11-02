#include "PathsGroup.h"


PathsGroup::PathsGroup(Path* firstPath)
{
	paths = new std::vector<Path*>();
	paths->push_back(firstPath);
	lastPath = firstPath;
}

PathsGroup::~PathsGroup()
{
}

void PathsGroup::connectPath(Path* newPath, cocos2d::Vec2 positionSelected){

	if (newPath->getPathType() == Path::PathType::Circle && lastPath->getPathType() == Path::PathType::Circle){
		connectCircleToCircle(newPath, positionSelected);
	}
	else if (newPath->getPathType() == Path::PathType::Circle && lastPath->getPathType() == Path::PathType::Line){
		connectLineToCircle(newPath, positionSelected);
	}
	else if (newPath->getPathType() == Path::PathType::Line && lastPath->getPathType() == Path::PathType::Circle){
		connectCircleToLine(newPath, positionSelected);
	}
}

void PathsGroup::connectCircleToCircle(Path* newPath, cocos2d::Vec2 positionSelected){
	PathSegment* closestPathSegment = getLastInsertedPath()->getPathSegmentClosestToPoint(positionSelected.x, positionSelected.y);

	cocos2d::Vec2 closestPathPosition = cocos2d::Vec2(closestPathSegment->getPositionX(), closestPathSegment->getPositionY());
	float distance = closestPathPosition.distance(positionSelected);

	if (closestPathSegment->isDirectionLastToNext()){
		CCLOG("directionInverted");
		newPath->invertPathDirection();
	}

	PathSegment* closestSegmentNewPath = newPath->getFirstPathSegment();

	paths->push_back(newPath);

	//Check for the direction of the path
	/*cocos2d::Vec2 oldSegmentDirection;
	closestPathSegment->getPathDirection(oldSegmentDirection);
	cocos2d::Vec2 direction = positionSelected - cocos2d::Vec2(closestSegmentNewPath->getPositionX(), closestSegmentNewPath->getPositionY());
	float angle = cocos2d::Vec2::angle(direction, oldSegmentDirection);
	if (angle < 0.0f){
		newPath->invertPathDirection();
	}*/

	lastPath->connectSegments(closestPathSegment, closestSegmentNewPath);


	lastPath = newPath;
}

void PathsGroup::connectCircleToLine(Path* newPath, cocos2d::Vec2 positionSelected){

}
void PathsGroup::connectLineToCircle(Path* newPath, cocos2d::Vec2 positionSelected){

}



