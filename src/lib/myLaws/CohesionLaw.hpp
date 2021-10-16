#pragma once
#include "Law.hpp";
#include "../myMath/Vec2.hpp"
#include <vector>
class Bird;

class CohesionLaw : public Law {
protected:
	float m_range = 50;
	float m_angle;
	float m_relaxation;
public:
	Vec2 compute(Bird& currentBird, const std::vector<Bird>& neighbors) const override;
};