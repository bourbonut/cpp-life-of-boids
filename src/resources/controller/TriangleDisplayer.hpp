#pragma once
#include "AgentDisplayer.hpp"
#include <vector>
#include "../../lib/myMath/Vec2.hpp"

class TriangleDisplayer : AgentDisplayer {
public :
	std::vector<Vec2> drawAgent() const override;
};