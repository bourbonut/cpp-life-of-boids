#include "../myMath/Vec2.hpp"
#include "../myMath/utils.hpp"
#include <vector>
class Bird;
#include "../../resources/Bird.hpp"
#include "AlignmentLaw.hpp"


Vec2 AlignmentLaw::compute(Bird& currentBird, const std::vector<Bird>& neighbors) const {

		Vec2 nextVelocity(0, 0);


	for (int i = 0; i < neighbors.size(); ++i) {
		//if ((currentBird.getPosition() - neighbors[i].getPosition()) < m_range) {
			Vec2 nextVelocity = currentBird.getVelocity() + neighbors[i].getVelocity();
			nextVelocity = nextVelocity / neighbors.size();
		//}
	}

	return nextVelocity;
};