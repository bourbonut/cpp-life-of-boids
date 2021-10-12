#pragma once
#include "../myMath/Vec2.hpp"
//need to add file in CMake.txt

class Law {
protected :
	float m_range;
	float m_angle;
	float m_relaxation;

public:
	Vec2 compute(std::vector<Bird> neighbors, Vec2 currentPos);
};

class CohesionLaw : public Personnage {
	Vec2 compute(std::vector<Bird> neighbors, Vec2 currentPos) {
		return Vec2(); //je veux ovverdie
	}
};