#pragma once
#include "Law.hpp";
#include "../myMath/Vec2.hpp"
#include <vector>
class Bird;

class CohesionLaw : public Law {
protected:
	float m_range = 10;
	float m_relaxation = 0.9;
public:
	Vec2 compute(Bird& currentBird, const std::vector<Bird>& neighbors) const override;
};