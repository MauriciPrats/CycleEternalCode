#include "PathManager.h"
#include "src/Util/Constants.h"
#include <math.h>
#include "cocos2d.h"

PathManager::PathManager()
{
	segmentId = 0;
	pathId = 0;
}

Path* PathManager::createCirclePath(const float x_position, const float y_position,const float starting_x_position, const float starting_y_position){
	//Has to create a path that contains the right Path Segments for a circle with the given attributes
	
	float radius = cocos2d::Vec2(x_position, y_position).distance(cocos2d::Vec2(starting_x_position, starting_y_position));
	float circlePerimeter = 2.0f * M_PI * radius;
	int ammountOfSegments = circlePerimeter / Constants::getInstance().PATH_SEGMENT_SIZE;
	float anglePerSegment = 360.0f / ammountOfSegments;
	anglePerSegment = anglePerSegment * (M_PI / 180); // Convert to radians

	float deltaStartingX = starting_x_position - x_position;
	float deltaStartingY = starting_y_position - y_position;

	float startingAngle = atan2(deltaStartingY,deltaStartingX);
	CCLOG("%f", startingAngle);
	std::vector<PathSegment*> segmentsVector = std::vector<PathSegment*>();
	long idPath = getNextPathId();

	//Create the segments
	for (int i = 0; i < ammountOfSegments; ++i){
		float newx = (cos((anglePerSegment*i) + startingAngle) * radius) + x_position;
		float newy = (sin((anglePerSegment*i) + startingAngle) * radius) + y_position;
		PathSegment* pathSegment = new PathSegment(idPath,getNextSegmentId(), newx, newy, true);
		segmentsVector.push_back(pathSegment);
	}

	//Link the segments
	for (int i = 0; i < segmentsVector.size(); ++i){
		if ((i - 1)>0){ segmentsVector[i]->setLastSegment(segmentsVector[i - 1]); }
		if ((i + 1) < segmentsVector.size()){ segmentsVector[i]->setNextSegment(segmentsVector[i + 1]); }
	}

	//Return the path
	Path* path = new Path(idPath,Path::PathType::Circle,segmentsVector[0]);
	return path;
}

Path* PathManager::createLinePath(const float x_position_start, const float y_position_start, 
	const float x_position_end, const float y_position_end){
	//Has to create a path that contains the right Path Segments for a line with the given attributes

	cocos2d::Vec2 startPoint = cocos2d::Vec2(x_position_start, y_position_start);
	cocos2d::Vec2 endPoint = cocos2d::Vec2(x_position_end, y_position_end);

	float distance = startPoint.distance(endPoint);
	int segments = distance / Constants::getInstance().PATH_SEGMENT_SIZE;

	cocos2d::Vec2 direction = endPoint - startPoint;
	direction.normalize();

	std::vector<PathSegment*> segmentsVector = std::vector<PathSegment*>();
	long idPath = getNextPathId();
	//Create the segments
	cocos2d::Vec2 lastPoint = startPoint;
	for (int i = 0; i < segments; ++i){
		cocos2d::Vec2 pathSegmentPosition = startPoint + (direction * Constants::getInstance().PATH_SEGMENT_SIZE * i);

		//PLACEHOLDER, need to calculate the direction
		PathSegment* pathSegment = new PathSegment(idPath,getNextSegmentId(),pathSegmentPosition.x, pathSegmentPosition.y, true);
		segmentsVector.push_back(pathSegment);
	}

	//Link the segments
	for (int i = 0; i < segmentsVector.size(); ++i){
		if ((i - 1)>0){ segmentsVector[i]->setLastSegment(segmentsVector[i - 1]); }
		if ((i + 1) < segmentsVector.size()){ segmentsVector[i]->setNextSegment(segmentsVector[i + 1]); }
	}

	//Return the path
	Path* path = new Path(idPath, Path::PathType::Line, segmentsVector[0]);
	return path;
}