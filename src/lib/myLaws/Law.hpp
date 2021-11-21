#pragma once
#include <vector>
#include <utility>

#include "../myMath/Vec2.hpp"
#include "../../resources/model/Agent.hpp"

using pair = std::pair<Vec2, Agent *>;

class Law {
protected:
	float m_relaxation;
	Law(const float &relaxation);


public:
	virtual Vec2 compute(Agent& currentAgent, const std::vector<pair>& neighbors) const = 0;
};
