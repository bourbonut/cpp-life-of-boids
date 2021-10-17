#pragma once
#include "Law.hpp"
#include "../myMath/Vec2.hpp"
#include <vector>
#include "../../resources/Agent.hpp"

class SeparationLaw : public Law {
public:
	Vec2 compute(Agent& currentAgent, const std::vector<Agent*>& neighbors) const override;
};