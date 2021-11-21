#pragma once
#include <vector>
#include <utility>

#include "Law.hpp"
#include "../myMath/Vec2.hpp"
#include "../../resources/model/Agent.hpp"

using pair = std::pair<Vec2, Agent *>;

class CohesionLaw : public Law {
protected:
	//float m_range = 10;
	//float m_relaxation = 0.9;
public:
	CohesionLaw(const float& relaxation);
	CohesionLaw();
	Vec2 compute(Agent& currentAgent, const std::vector<pair>& neighbors) const override;
};
