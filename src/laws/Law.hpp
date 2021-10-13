#pragma once
#include "../myMath/Vec2.hpp"
//need to add file in CMake.txt

interface Law {
protected :
	float m_range;
	float m_angle;
	float m_relaxation;

public:
	Vec2 compute(Bird currentBird, std::vector<Bird> neighbors);
};

class CohesionLaw : public Law {
	Vec2 compute(Bird currentBird, std::vector<Bird> neighbors) {
		
		return Vec2(); //je veux ovverdie
	}
};

class SeparationLaw : public Law {
	Vec2 compute(Bird currentBird, std::vector<Bird> neighbors) {
		
	}
};