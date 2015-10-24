#include "PathSegment.h"


PathSegment::PathSegment(int position_x, int position_y, PathSegment* lastSegment, PathSegment* nextSegment, bool directionlastToNext)
{
	this->position_x = position_x;
	this->position_y = position_y;
	this->lastSegment = lastSegment;
	this->nextSegment = nextSegment;
	this->directionLastToNext = directionlastToNext;
}


PathSegment::~PathSegment()
{
	lastSegment = nullptr;
	nextSegment = nullptr;
}

const bool PathSegment::hasNext() const {
	 if (directionLastToNext){ return nextSegment != nullptr; } 
	 else{ return lastSegment != nullptr; }
}
