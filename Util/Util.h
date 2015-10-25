#pragma once

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include <CCFileUtils.h>
#include "cocos2d.h"

static class Util
{
public:	

	// trim from start
	static inline std::string &ltrim(std::string &s) {
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
		return s;
	}

	// trim from end
	static inline std::string &rtrim(std::string &s) {
		s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
		return s;
	}

	// trim from both ends
	static inline std::string &trim(std::string &s) {
		return ltrim(rtrim(s));
	}

	// split string into vector with delimiter using references
	static inline std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
		std::stringstream ss(s);
		std::string item;
		while (std::getline(ss, item, delim)) {
			elems.push_back(item);
		}
		return elems;
	}

	// split string into vector with delimiter
	static inline std::vector<std::string> split(const std::string &s, char delim) {
		std::vector<std::string> elems;
		split(s, delim, elems);
		return elems;
	}

	static float getCurrentAngle(cocos2d::Node* node)
	{
		float rotAng = node->getRotation();

		if (rotAng >= 180.f)
		{
			rotAng -= 360.f;
		}
		else if (rotAng < -180.f)
		{
			rotAng += 360.f;
		}

		// negative angle means node is facing to its left
		// positive angle means node is facing to its right
		return rotAng;
	}

	static float getAngleDifference(float angle1, float angle2)
	{
		float diffAngle = (angle1 - angle2);

		if (diffAngle >= 180.f)
		{
			diffAngle -= 360.f;
		}
		else if (diffAngle < -180.f)
		{
			diffAngle += 360.f;
		}

		// how much angle the node needs to rotate
		return diffAngle;
	}

	static float getAngleOfTwoVectors(cocos2d::Point vec1, cocos2d::Point vec2)
	{
		auto vectorFromVec1ToVec2 = vec2 - vec1;
		// the angle between two vectors
		return CC_RADIANS_TO_DEGREES(-vectorFromVec1ToVec2.getAngle());
	}

	static void rotateNodeToPoint(cocos2d::Node* node, cocos2d::Point point)
	{
		float angleNodeToRotateTo = getAngleOfTwoVectors(node->getPosition(), point);
		float nodeCurrentAngle = getCurrentAngle(node);

		float diffAngle = getAngleDifference(angleNodeToRotateTo, nodeCurrentAngle);

		float rotation = nodeCurrentAngle + diffAngle;

		node->setRotation(rotation);
	}
};


