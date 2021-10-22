#include "HuntingLaw.hpp"
#include "../myMath/Vec2.hpp"
#include "../myMath/utils.hpp"
#include <vector>
#include "../../resources/model/Agent.hpp"
#include "../../resources/model/Flock.hpp"

HuntingLaw::HuntingLaw() : Law(20.f) {};

HuntingLaw::HuntingLaw(Flock* pFlock) : Law(20.f) {
	m_pFlock = pFlock;
}

Vec2 HuntingLaw::compute(Agent& currentAgent, const std::vector<Agent*>& neighbors) const {
	Vec2 newVelocity{};

	if (neighbors.size() > 0) {
		float weight = distance((currentAgent).getPosition(), (*neighbors[0]).getPosition());
		if (weight < currentAgent.getBodySize()*3) {
			(*m_pFlock).destroyAgent((*neighbors[0]).getPosition());
			currentAgent.setSize((currentAgent.getBodySize()+1));
		}
		newVelocity = (*neighbors[0]).getVelocity() + ((currentAgent).getPosition() - (currentAgent).getPosition()) * weight;
	}

	return newVelocity * m_relaxation;
};