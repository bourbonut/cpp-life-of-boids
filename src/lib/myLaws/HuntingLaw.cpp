#include "HuntingLaw.hpp"
#include "../myMath/Vec2.hpp"
#include "../myMath/utils.hpp"
#include <vector>
#include "../../resources/model/Agent.hpp"
#include "../../resources/model/Flock.hpp"

Vec2 HuntingLaw::compute(Agent& currentAgent, const std::vector<Agent*>& neighbors) const {
	Vec2 newVelocity{};
	float weight;

	if (neighbors.size() > 0) {
		weight = distance((currentAgent).getPosition(), (*neighbors[0]).getPosition());
		newVelocity = (*neighbors[0]).getVelocity() + ((currentAgent).getPosition() - (currentAgent).getPosition()) * weight / m_range;
	}

	return newVelocity;
};