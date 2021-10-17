#pragma once

#include "Law.hpp"
#include "../myMath/Vec2.hpp"
#include <vector>
#include "../../resources/Agent.hpp"

class AlignmentLaw : public Law {
public:
	Vec2 compute(Agent& currentBird, const std::vector<Agent*>& neighbors) const override;
};
