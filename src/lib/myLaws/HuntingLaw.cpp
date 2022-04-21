#include <vector>
#include <utility>

#include "HuntingLaw.hpp"
#include "../myMath/Vec2.hpp"
#include "../myMath/utils.hpp"
#include "../../resources/model/Agent.hpp"
#include "../../resources/model/Flock.hpp"
#include "../../resources/model/Eagle.hpp"

using pair = std::pair<Vec2, Agent *>;

HuntingLaw::HuntingLaw() : Law(20.f), m_manualHunting(false) { m_pFlock = nullptr; };

HuntingLaw::HuntingLaw(Flock* pFlock) : Law(20.f), m_manualHunting(false) {
	m_pFlock = pFlock;
}

HuntingLaw::HuntingLaw(Flock* pFlock, bool manualHunting) : Law(20.f), m_manualHunting(manualHunting) {
	m_pFlock = pFlock;
};

Vec2 HuntingLaw::compute(Agent& currentAgent, const std::vector<pair>& neighbors) const {
	Vec2 newVelocity{};
	//To compute with the front of the triangle of the agent

	if (neighbors.size() > 0) {
		Vec2 pos = currentAgent.getPosition();

		pair data = neighbors[0];
		Vec2 posNeighbor = std::get<0>(data);
		Agent* neighbor = std::get<1>(data);
		float weight = distance(pos, posNeighbor);


		if (weight < currentAgent.getBodySize()*1.5) {
			(*neighbor).setDestruction();

			if (currentAgent.getBodySize() < 26) currentAgent.setSize((currentAgent.getBodySize() + 5));
			else {
				currentAgent.setSize(10);
				currentAgent.setVelocity(Vec2{ 5,0 });
				Vec2 vel = Vec2{-5,-5};

				(*m_pFlock).addBornAgent(new Eagle{ pos, vel,10,50,100, 15.f, Color::Red, HuntingLaw{m_pFlock, false}});
				(*m_pFlock).addBornAgent(new Eagle{ pos, Vec2{ 5,5 },10,50,100, 15.f, Color::Red, HuntingLaw{m_pFlock, false} });
			}
		}

		//If we are not in manual mode, we set the speed to be going to the agent's next position
		if(!m_manualHunting) newVelocity = (*neighbor).getVelocity() * weight;
	}

	return newVelocity * m_relaxation;
};
