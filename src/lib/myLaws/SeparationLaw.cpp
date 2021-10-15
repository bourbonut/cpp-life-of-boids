#include "../myMath/Vec2.hpp"
#include "../myMath/utils.hpp"
#include <vector>
class Bird;
#include "../../resources/Bird.hpp"

Vec2 SeparationLaw::compute(Bird& currentBird, const std::vector<Bird>& neighbors) const {

	Vec2 result;
	float distBetwA = 0, weight = 0;

	//std::cout << "current : "; currentBird.print();
	//std::cout << "0 : "; neighbors[0].print();

	//for each neighbor bird, add to a final vector the weigthed input of the neighbor bird
	//std::cout << "m_range : " << m_range << std::endl;
	for (Bird b : neighbors)
	{
		if (!(b.getPosition() == currentBird.getPosition())) {
			distBetwA = distance(b.getPosition(), currentBird.getPosition());
			//std::cout << "dist : " << distBetwA << std::endl;
			//Get the weight from the inverse of the square, depending on the distance between the two agents
			//weight = 1 / ((distBetwA / m_range) * (distBetwA / m_range));
			weight = 1 / ((distBetwA / 50) * (distBetwA / 50));
			//std::cout << "weight : " << weight << std::endl;
			//Calculates a vector between agent b and this, and mutiplies it by the current weight of agent b
			result = result + (b.getPosition() - currentBird.getPosition()) * weight;
		}

	}

	//divide the actual final vector by the number of neighbor birds to get a final vector pointing to the barycenter needed
	//result = result / neighbors.size();

	return result;

}