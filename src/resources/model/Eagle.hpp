#pragma once

#include "Agent.hpp"
#include "../../lib/myMath/Vec2.hpp"
#include "../../lib/myLaws/HuntingLaw.hpp"
#include "../../lib/myLaws/SeparationLaw.hpp"
#include <vector>

class Eagle : public Agent {
private:
	HuntingLaw m_huntingLaw;
	SeparationLaw m_separationLaw;

public:
	Eagle(); // Constructeur sans arguments
	Eagle(const Vec2& position, const Vec2& velocity);
	~Eagle() { std::cout << "Eagle actually destroyed" << std::endl; };

	void computeLaws(const std::vector<Agent*>& allNeighbors, const std::vector<Agent*>& preyNeighbors);

	//void computeLaws(const std::vector<Agent*>& neighbors) override;

	void print() const;

};
