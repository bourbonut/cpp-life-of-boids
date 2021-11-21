#pragma once
#include <vector>
#include <utility>

#include "Law.hpp"
#include "../myMath/Vec2.hpp"
#include "../../resources/model/Agent.hpp"
#include "../../resources/model/Flock.hpp"

using pair = std::pair<Vec2, Agent *>;

class HuntingLaw : public Law {  // A changer
private:
	bool m_manualHunting;

public:
	HuntingLaw();
	HuntingLaw(Flock* pFlock);
	HuntingLaw(Flock* pFlock, bool manualHunting);
	Vec2 compute(Agent& currentAgent, const std::vector<pair>& neighbors) const override;
	Flock* m_pFlock;
};
