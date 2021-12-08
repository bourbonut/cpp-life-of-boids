#pragma once
#include <vector>
#include <utility>

#include "Agent.hpp"
#include "../../lib/myMath/Vec2.hpp"
#include "../../lib/myLaws/HuntingLaw.hpp"
#include "../../lib/myLaws/SeparationLaw.hpp"

using pair = std::pair<Vec2, Agent *>;
using pairNP = std::pair<std::vector<pair>, std::vector<pair>>;

class Eagle : public Agent {
private:
	HuntingLaw m_huntingLaw;
	SeparationLaw m_separationLaw;

public:
	Eagle();
	Eagle(const Vec2& position, const Vec2& velocity);
	Eagle(const Vec2& position, const Vec2& velocity, const int& bodySize, const int& viewAngle, const int& range, const float& speedRelaxation, const Color& color);
	Eagle(const Vec2& position, const Vec2& velocity, const int& bodySize, const int& viewAngle, const int& range, const float& speedRelaxation, const Color& color, const HuntingLaw& huntLaw);

	void computeLaws(const pairNP& neighbors) override;

};

std::ostream& operator<<(std::ostream& os, const Eagle& obj);
