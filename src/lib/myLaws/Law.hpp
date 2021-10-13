#pragma once
#include "../myMath/Vec2.hpp"
class Bird;
#include "../../resources/Bird.hpp"
#include <vector>
//need to add file in CMake.txt

class Law {
protected:
	float m_range;
	float m_angle;
	float m_relaxation;
	std::vector<Vec2> getCoordinatesArray(const std::vector<Bird>& neighbors) const;
	Vec2 computeAgentsBarycenter(const std::vector<Bird>& neighbors) const;

public:
	virtual Vec2 compute(Bird& currentBird, const std::vector<Bird>& neighbors) const = 0;
	//ILaw() : default;
	//~ILaw() : default;
};

