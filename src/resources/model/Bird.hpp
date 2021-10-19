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

	void computeLaws(const std::vector<Agent*>& neighbors) override;
	Vec2 computeAlignment(const std::vector<Agent*>& neighbors) override; // Obligé de rajouter cette méthode pour la tester unitairement

	void print() const;

};