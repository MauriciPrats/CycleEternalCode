#pragma once

#include "cocos2d.h"

class PathSegment
{
public:
	PathSegment(long idPath,long idPathSegment, float position_x, float position_y, bool directionLastToNext);
	~PathSegment();

	const long getIdPathSegment() const { return idPathSegment; }
	const bool hasNext() const;

	void setLastSegment(PathSegment* lastSegment){this->lastSegment = lastSegment;}
	void setNextSegment(PathSegment* nextSegment){ this->nextSegment = nextSegment; }

	void linkToLayer(cocos2d::Layer* layer);
	void removeFromLayer(cocos2d::Layer* layer);

	PathSegment* getNextPathSegment() const { if (directionLastToNext){ return nextSegment; }else{ return lastSegment; } }
	void getPathDirection(cocos2d::Vec2& result) const;
	void setDirection(bool newDirection){ directionLastToNext = newDirection; }
	const float getPositionX() const { return position_x; }
	const float getPositionY() const { return position_y; }
	const long getIdPath() const { return idPath; }
	const bool isDirectionLastToNext() const { return directionLastToNext; }

private:

	//Unique ID
	long idPathSegment;
	long idPath;
	bool directionLastToNext;
	cocos2d::Layer* layer;
	PathSegment* lastSegment;
	PathSegment* nextSegment;

	cocos2d::Sprite* sprite;

	float position_x, position_y;
};

