#pragma once
#include "AgentDisplayer.hpp"
#include <array>
#include "../../lib/myMath/Vec2.hpp"

class TriangleDisplayer : AgentDisplayer<6> {
public :
	TriangleDisplayer(const Agent *pAgent);
	std::array<Vec2, 6> drawAgent() const override;
};