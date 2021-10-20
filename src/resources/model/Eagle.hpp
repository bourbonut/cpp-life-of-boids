#pragma once

#include "Agent.hpp"
#include "../../lib/myMath/Vec2.hpp"
#include <vector>

class Eagle : public Agent {
private:
	//CohesionLaw m_cohesionLaw;// = CohesionLaw{};
	//SeparationLaw m_separationLaw;// = SeparationLaw{};
	//AlignmentLaw m_AlignmentLaw;

public:
	Eagle(); // Constructeur sans arguments
	Eagle(const Vec2& position, const Vec2& velocity);

	//void computeLaws(const std::vector<Agent*>& neighbors) override;

	void print() const;

};
