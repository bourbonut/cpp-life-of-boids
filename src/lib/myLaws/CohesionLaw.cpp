#include <vector>
#include <utility>

#include "CohesionLaw.hpp"
#include "../myMath/Vec2.hpp"
#include "../myMath/utils.hpp"
#include "../../resources/model/Agent.hpp"

using pair = std::pair<Vec2, Agent *>;

CohesionLaw::CohesionLaw(const float& relaxation) : Law(relaxation) {};
CohesionLaw::CohesionLaw() : Law(1.f) {};

Vec2 CohesionLaw::compute(Agent& currentAgent, const std::vector<pair>& neighbors) const {

	Vec2 newVelocity{};

	if (neighbors.size() > 0) {
		Vec2 pos = currentAgent.getPosition();
		for (pair data : neighbors){
			Vec2 neighbor = std::get<0>(data);
			if (distance(neighbor, pos) > 30) { // !(b.getPosition() == currentBird.getPosition())
				newVelocity = newVelocity + (neighbor - pos);
			}
		}
		// Divide by the size of neighbors to get the barycenter
		newVelocity = newVelocity / (float) neighbors.size();

	}
	return newVelocity * m_relaxation;
};
