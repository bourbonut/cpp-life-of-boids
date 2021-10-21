#pragma once

#include "Agent.hpp"
#include "../../lib/myMath/Vec2.hpp"
#include "../../lib/myLaws/SeparationLaw.hpp"
#include <vector>

class Eagle : public Agent {
private:
	HuntingLaw m_huntingLaw;

public:
	Eagle(); // Constructeur sans arguments
	Eagle(const Vec2& position, const Vec2& velocity);

	//void computeLaws(const std::vector<Agent*>& neighbors) override;

	void print() const;

};
