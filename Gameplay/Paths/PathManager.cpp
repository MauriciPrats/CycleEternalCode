#include "PathManager.h"

PathManager::PathManager()
{

}

Path* PathManager::createCirclePath(const float x_position, const float y_position, const float radius){
	//Has to create a path that contains the right Path Segments for a circle with the given attributes
	
	
	//PLACEHOLDER START
	PathSegment* firstPathSegment = new PathSegment(10, 10, nullptr, nullptr, true);
	Path* path = new Path(firstPathSegment);
	return path;
	//PLACEHOLDER END
}

Path* PathManager::createLinePath(const float x_position_start, const float y_position_start, 
	const float x_position_end, const float y_position_end){
	//Has to create a path that contains the right Path Segments for a line with the given attributes

	//PLACEHOLDER START
	PathSegment* firstPathSegment = new PathSegment(10, 10, nullptr, nullptr, true);
	Path* path = new Path(firstPathSegment);
	return path;
	//PLACEHOLDER END
}