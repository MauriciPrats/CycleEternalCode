#pragma once
class PathSegment
{
public:
	PathSegment();
	~PathSegment();

private:
	PathSegment* lastSegment;
	PathSegment* nextSegment;

};

