#include "Path.h"
#include "cocos2d.h"


Path::Path(PathSegment* firstSegment)
{
	firstPathSegment = firstSegment;
	pathSegments = new std::map<long, PathSegment*>();
	std::map<long, PathSegment*>* unconnectedSegments = recalculatePathSegments();
	clearSegments(unconnectedSegments);
}


Path::~Path()
{
	clearSegments(pathSegments);
}

std::map<long, PathSegment*>* Path::recalculatePathSegments(){
	
	std::map<long, PathSegment*> *newPathSegments = new std::map<long, PathSegment*>();
	
	PathSegment* actualSegment = firstPathSegment;
	pathSegments->erase(actualSegment->getIdPathSegment());
	newPathSegments->insert(std::make_pair(actualSegment->getIdPathSegment(), actualSegment));

	while (actualSegment->hasNext()){
		actualSegment = actualSegment->getNextPathSegment();
		pathSegments->erase(actualSegment->getIdPathSegment());
		newPathSegments->at(actualSegment->getIdPathSegment()) = actualSegment;
		
	}

	std::map<long, PathSegment*> *unconnectedSegments = pathSegments;
	pathSegments = newPathSegments;

	return unconnectedSegments;
}

void Path::clearSegments(std::map<long, PathSegment*>* segmentsToClear){
	std::map<long, PathSegment*>::iterator it = segmentsToClear->begin();
	while (it != segmentsToClear->end()){
		delete it->second;
		segmentsToClear->erase(it);
		it = segmentsToClear->begin();
	}

	//We free the memory of the vector
	delete segmentsToClear;
}