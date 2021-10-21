#include "CohesionLaw.hpp"
#include "CohesionLaw.hpp"
#include "../myMath/Vec2.hpp"
#include "../myMath/utils.hpp"
#include <vector>
#include "../../resources/model/Agent.hpp"

CohesionLaw::CohesionLaw(const float& relaxation) : Law(relaxation) {};
CohesionLaw::CohesionLaw() : Law(1.f) {};

Vec2 CohesionLaw::compute(Agent& currentAgent, const std::vector<Agent*>& neighbors) const {

	Vec2 newVelocity{};
	float distBetwA = 0, weight = 0;

	for (Agent* b : neighbors)
	{
		if (abs(distance((*b).getPosition(), currentAgent.getPosition())) > 30) { // !(b.getPosition() == currentBird.getPosition())
			distBetwA = distance((*b).getPosition(), currentAgent.getPosition());
			weight = (distBetwA / (*b).getRange());
			newVelocity = newVelocity + ((*b).getPosition() - currentAgent.getPosition()) * weight;
		}

	}
	return newVelocity * m_relaxation;
};