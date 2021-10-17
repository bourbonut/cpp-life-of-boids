#include "AlignmentLaw.hpp"
#include "../myMath/Vec2.hpp"
#include "../myMath/utils.hpp"
#include <vector>
#include "../../resources/Agent.hpp"


Vec2 AlignmentLaw::compute(Agent& currentAgent, const std::vector<Agent*>& neighbors) const {

		Vec2 nextVelocity(0, 0);


	for (int i = 0; i < neighbors.size(); ++i) {
		//if ((currentBird.getPosition() - neighbors[i].getPosition()) < m_range) {
			Vec2 nextVelocity = currentAgent.getVelocity() + (*neighbors[i]).getVelocity();
			nextVelocity = nextVelocity / neighbors.size();
		//}
	}

	return nextVelocity;
};