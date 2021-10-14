#include "../myMath/Vec2.hpp"
#include "../myMath/utils.hpp"
#include <vector>
class Bird;
#include "../../resources/Bird.hpp"


Vec2 AlignmentLaw::computeposition(Bird& currentBird, const std::vector<Bird>& neighbors) const {

	float ALIGNMENT_RADIUS = 50;
		Vec2 nextVelocity(0, 0);


	for (int i = 0; i < neighbors.size(); ++i) {
		if ((currentBird.getPosition() - neighbors[i]) < ALIGNMENT_RADIUS) {
			Vec2 nextVelocity = currentBird.getVelocity() + neighbors[i];
			Vec2 nextVelocity = nextVelocity / neighbors.size();
		}
	}

	return Vec2{};
};