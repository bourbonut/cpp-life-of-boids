#pragma once

#include "Law.hpp"
#include "../myMath/Vec2.hpp"
#include <vector>

class Bird;

class AlignmentLaw : public Law {
public:
	Vec2 compute(Bird& currentBird, const std::vector<Bird>& neighbors) const override;
};
