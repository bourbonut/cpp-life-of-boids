#pragma once
#include <vector>
#include <utility>

#include "Agent.hpp"
#include "../../lib/myMath/Vec2.hpp"
#include "../../lib/myLaws/SeparationLaw.hpp"
#include "../../lib/myLaws/CohesionLaw.hpp"
#include "../../lib/myLaws/AlignmentLaw.hpp"

using pair = std::pair<Vec2, Agent *>;
using pairNP = std::pair<std::vector<pair>, std::vector<pair>>;

class Bird : public Agent{
private:
	CohesionLaw m_cohesionLaw;
	AlignmentLaw m_alignmentLaw;
	SeparationLaw m_separationLaw;

public:
	Bird();
	Bird(const Vec2& position, const Vec2& velocity);
	Bird(const Vec2& position, const Vec2& velocity, const int& bodySize, const int& viewAngle, const int& range, const float &speedRelaxation, const Color& color);
	Bird(const Vec2& position, const Vec2& velocity, const int& bodySize, const int& viewAngle, const int& range, const float &speedRelaxation, const Color& color, const CohesionLaw &cohesionLaw, const AlignmentLaw &alignmentLaw, const SeparationLaw &separationLaw);

	void computeLaws(const pairNP& neighbors) override;

	void print() const;

};
