#include <vector>
#include <utility>

#include "AlignmentLaw.hpp"
#include "../myMath/Vec2.hpp"
#include "../myMath/utils.hpp"
#include "../../resources/model/Agent.hpp"

using pair = std::pair<Vec2, Agent *>;

AlignmentLaw::AlignmentLaw(const float& relaxation) : Law(relaxation){};
AlignmentLaw::AlignmentLaw() : Law(1.f){};

Vec2 AlignmentLaw::compute(Agent&, const std::vector<pair>& neighbors) const {

	Vec2 nextVelocity(0, 0);
	if (neighbors.size() > 0) {
		for (pair data : neighbors) {
			nextVelocity = nextVelocity + (*std::get<1>(data)).getVelocity();
		}
		nextVelocity = nextVelocity / (float)neighbors.size();
	}

	return nextVelocity * m_relaxation;
};
