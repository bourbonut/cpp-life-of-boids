#pragma once
#include "../Agent.hpp"
#include <vector>
#include "../../lib/myMath/Vec2.hpp"

class AgentDisplayer {
protected:
	Agent* m_pAgent;

public:
	virtual std::vector<Vec2> drawAgent() const = 0;
};