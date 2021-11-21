#pragma once
#include <vector>
#include <utility>

#include "Law.hpp"
#include "../myMath/Vec2.hpp"
#include "../../resources/model/Agent.hpp"

using pair = std::pair<Vec2, Agent *>;

class AlignmentLaw : public Law {
public:
	AlignmentLaw(const float& relaxation);
	AlignmentLaw();
	Vec2 compute(Agent& currentAgent, const std::vector<pair>& neighbors) const override;
};
