#pragma once
#include "Agent.hpp"
#include "../../lib/myMath/Vec2.hpp"
#include <vector>
#include "../../lib/myLaws/SeparationLaw.hpp"
#include "../../lib/myLaws/CohesionLaw.hpp"
#include "../../lib/myLaws/AlignmentLaw.hpp"


class Bird : public Agent{
private:
	CohesionLaw m_cohesionLaw;// = CohesionLaw{};
	SeparationLaw m_separationLaw;// = SeparationLaw{};
	AlignmentLaw m_AlignmentLaw;

public:
	Bird(); // Constructeur sans arguments
	//Bird(const Bird& other);
	Bird(const Vec2& position, const Vec2& velocity);
	Bird(const Vec2& position, const Vec2& velocity, const int& bodySize, const int& viewAngle, const int& range, const Color& color);

	void computeLaws(const std::vector<Agent*>& neighbors) override;

	void print() const;

};