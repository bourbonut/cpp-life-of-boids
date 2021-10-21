#include "CohesionLaw.hpp"
#include "../myMath/Vec2.hpp"
#include "../myMath/utils.hpp"
#include <vector>
#include "../../resources/model/Agent.hpp"

Vec2 CohesionLaw::compute(Agent& currentAgent, const std::vector<Agent*>& neighbors) const {

	Vec2 newVelocity{};

	if (neighbors.size() > 0) {
		float distBetwA = 0, weight = 0;

		for (Agent* b : neighbors)
		{
			if (distance((*b).getPosition(), currentAgent.getPosition()) > 30) { // !(b.getPosition() == currentBird.getPosition())

				newVelocity = newVelocity + ((*b).getPosition() - currentAgent.getPosition());

			}

		}

		// Divide by the size of neighbors to get the barycenter
		newVelocity = newVelocity / neighbors.size();

	}

	return newVelocity;
};