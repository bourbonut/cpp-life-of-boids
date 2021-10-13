#include "../myMath/Vec2.hpp"
#include "../myMath/utils.hpp"
#include <vector>
class Bird;
#include "../../resources/Bird.hpp"

Vec2 CohesionLaw::compute(Bird& currentBird, const std::vector<Bird>& neighbors) const {

	//We get the barycenter of all the VALID neighbors
	Vec2 barycenter = computeAgentsBarycenter(neighbors);

	//We calculate the coordinates of the velocity vector
	//We want to use barycenter.x, or even barycenter - this.position 
	Vec2 newVelocity{ barycenter.x - currentBird.getPosition().x, barycenter.y - currentBird.getPosition().y };

	return Vec2{};
};