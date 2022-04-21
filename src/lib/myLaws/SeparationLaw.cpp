#include <vector>
#include <utility>

#include "SeparationLaw.hpp"
#include "../myMath/Vec2.hpp"
#include "../myMath/utils.hpp"
#include "../../resources/model/Agent.hpp"

using pair = std::pair<Vec2, Agent *>;

SeparationLaw::SeparationLaw(const float& relaxation) : Law(relaxation) {};
SeparationLaw::SeparationLaw() : Law(1.f) {};

Vec2 SeparationLaw::compute(Agent& currentAgent, const std::vector<pair> &neighbors) const {

	Vec2 result{};
	float distBetwA = 0, weight = 0;

	Vec2 pos = currentAgent.getPosition();
	for (pair data : neighbors){
		Vec2 neighbor = std::get<0>(data);
		if (!(neighbor == pos)) {
			distBetwA = distance(neighbor, pos);
			weight = 1 / ((distBetwA) * (distBetwA));
			result = result + (pos - neighbor) * weight;
		}

	}

	return result * m_relaxation;

}
