#include "Path.h"
#include "cocos2d.h"

Path::Path(long idPath,PathSegment* firstSegment)
{
	this->idPath = idPath;
	this->firstPathSegment = firstSegment;
	pathSegments = new std::map<long, PathSegment*>();
	recalculatePathSegments();
}

Path::~Path()
{
	clearSegments(pathSegments);
}

void Path::recalculatePathSegments(){
	
	std::map<long, PathSegment*> *newPathSegments = new std::map<long, PathSegment*>();
	
	PathSegment* actualSegment = firstPathSegment;
	pathSegments->erase(actualSegment->getIdPathSegment());
	newPathSegments->insert(std::make_pair(actualSegment->getIdPathSegment(), actualSegment));

	//We only cover the segments that are in the path
	while (actualSegment->hasNext()){
		actualSegment = actualSegment->getNextPathSegment();
		if (actualSegment->getIdPath() == idPath){
			pathSegments->erase(actualSegment->getIdPathSegment());
			newPathSegments->insert(std::make_pair(actualSegment->getIdPathSegment(), actualSegment));
		}
	}
	std::map<long, PathSegment*> *unconnectedSegments = pathSegments;
	clearSegments(unconnectedSegments);
	pathSegments = newPathSegments;

}

void Path::connectSegments(PathSegment* segmentToConnect, PathSegment* segmentNewPath){
	segmentToConnect->setNextSegment(segmentNewPath);
	recalculatePathSegments();
}

void Path::setFirstPathSegment(PathSegment* pathSegment){
	firstPathSegment = pathSegment;
	recalculatePathSegments();
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

void Path::linkPathToLayer(cocos2d::Layer* layer){
	PathSegment* actualSegment = firstPathSegment;
	actualSegment->linkToLayer(layer);
	while (actualSegment->hasNext()){
		actualSegment = actualSegment->getNextPathSegment();
		actualSegment->linkToLayer(layer);
	}
}

void Path::unlinkPathToLayer(cocos2d::Layer* layer){
	PathSegment* actualSegment = firstPathSegment;
	actualSegment->removeFromLayer(layer);
	while (actualSegment->hasNext()){
		actualSegment = actualSegment->getNextPathSegment();
		actualSegment->removeFromLayer(layer);
	}
}