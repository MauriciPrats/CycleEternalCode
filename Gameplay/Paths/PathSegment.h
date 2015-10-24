#pragma once

class PathSegment
{
public:
	PathSegment(int position_x, int position_y,PathSegment* lastSegment,PathSegment* nextSegment,bool directionlastToNext);
	~PathSegment();

	const long getIdPathSegment() const { return idPathSegment; }
	const bool hasNext() const;

	PathSegment* getNextPathSegment() const { if (directionLastToNext){ return nextSegment; }else{ return lastSegment; } }

private:

	//Unique ID
	long idPathSegment;
	bool directionLastToNext;

	PathSegment* lastSegment;
	PathSegment* nextSegment;

	int position_x, position_y;

	

};

