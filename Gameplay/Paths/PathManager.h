#pragma once
#include "src/Gameplay/Paths/Path.h"

class PathManager
{
public:

	// Returns the instance of PathManager as a reference
	static PathManager& getInstance()
	{
		static PathManager pathManagerInstance; //This is the only instance created (Lazy initialization)
		return pathManagerInstance;
	}

	Path* createCirclePath(const float x_position, const float y_position, const float radius);
	Path* createLinePath(const float x_position_start, const float y_position_start, 
		const float x_position_end, const float y_position_end);

private:

	long segmentId;
	long pathId;

	long getNextSegmentId(){ segmentId++; return segmentId; }
	long getNextPathId(){ pathId++; return pathId; }
	PathManager();
	PathManager(PathManager const&); //This overrides the implicit constructor
	void operator=(PathManager const&); //This overrides the implicit = operator
};

