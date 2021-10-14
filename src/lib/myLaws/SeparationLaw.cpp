#include "../myMath/Vec2.hpp"
#include "../myMath/utils.hpp"
#include <vector>
class Bird;
#include "../../resources/Bird.hpp"
#include "SeparationLaw.hpp"

Vec2 SeparationLaw::compute(Bird& currentBird, const std::vector<Bird>& neighbors) const {

	Vec2 result;
	float distBetwA = 0, weight = 0;

	//for each neighbor bird, add to a final vector the weigthed input of the neighbor bird
	for (Bird b : neighbors)
	{
		distBetwA = distance(b.getPosition(), currentBird.getPosition());
		//Get the weight from the inverse of the square, depending on the distance between the two agents
		weight = 1 / ((distBetwA / m_range) * (distBetwA / m_range));
		//Calculates a vector between agent b and this, and mutiplies it by the current weight of agent b
		result = result + (b.getPosition() - currentBird.getPosition()) * weight;
	}

	//divide the actual final vector by the number of neighbor birds to get a final vector pointing to the barycenter needed
	result = result / neighbors.size();

	return result;

}
