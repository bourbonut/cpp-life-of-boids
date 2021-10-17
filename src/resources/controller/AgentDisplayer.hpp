#pragma once
#include "../Agent.hpp"
#include <array>
#include "../../lib/myMath/Vec2.hpp"

template <int m_nbPoints>
class AgentDisplayer {
protected:
	const Agent* m_pAgent;

public:
	virtual std::array<Vec2, m_nbPoints> drawAgent() const = 0;
};