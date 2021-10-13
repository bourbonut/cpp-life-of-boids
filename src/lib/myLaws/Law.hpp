#pragma once
#include "../myMath/Vec2.hpp"
class Bird;
#include "../../resources/Bird.hpp"
#include <vector>
//need to add file in CMake.txt

class ILaw {
protected:
	float m_range;
	float m_angle;
	float m_relaxation;

public:
	virtual Vec2 compute(Bird& currentBird, const std::vector<Bird>& neighbors) const = 0;
	//ILaw() : default;
	//~ILaw() : default;
};

