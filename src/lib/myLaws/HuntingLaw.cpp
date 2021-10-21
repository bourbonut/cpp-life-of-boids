#include "HuntingLaw.hpp"
#include "../myMath/Vec2.hpp"
#include "../myMath/utils.hpp"
#include <vector>
#include "../../resources/model/Agent.hpp"

Vec2 HuntingLaw::compute(Agent& currentAgent, const std::vector<Agent*>& neighbors) const {
	return Vec2(0, 0);
};