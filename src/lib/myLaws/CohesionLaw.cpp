#include "CohesionLaw.hpp"
#include "../myMath/Vec2.hpp"
#include "../myMath/utils.hpp"
#include <vector>
#include "../../resources/model/Agent.hpp"

Vec2 CohesionLaw::compute(Agent& currentAgent, const std::vector<Agent*>& neighbors) const {

	Vec2 newVelocity{};
	float distBetwA = 0, weight = 0;

	//std::cout << "current : "; currentBird.print();
	//std::cout << "0 : "; neighbors[0].print();

	//for each neighbor bird, add to a final vector the weigthed input of the neighbor bird
	//std::cout << "m_range : " << m_range << std::endl;
	for (Agent* b : neighbors)
	{
		if (distance((*b).getPosition(), currentAgent.getPosition()) > 30) { // !(b.getPosition() == currentBird.getPosition())
			distBetwA = distance((*b).getPosition(), currentAgent.getPosition());

			weight = (distBetwA / m_range);

			newVelocity = newVelocity + ((*b).getPosition() - currentAgent.getPosition()) * weight;
		}

	}

	//divide the actual final vector by the number of neighbor birds to get a final vector pointing to the barycenter needed
	//result = result / neighbors.size();

	//newVelocity.string();
	return newVelocity;
};