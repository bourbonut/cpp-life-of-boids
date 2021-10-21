#pragma once
#include "Law.hpp";
#include "../myMath/Vec2.hpp"
#include <vector>
#include "../../resources/model/Agent.hpp"

class HuntingLaw : public Law {  // A changer
public:
	HuntingLaw();
	Vec2 compute(Agent& currentAgent, const std::vector<Agent*>& neighbors) const override;
};
