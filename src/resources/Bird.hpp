#pragma once
#include "Agent.hpp"
#include "../lib/myMath/Vec2.hpp"
#include <vector>
#include "../lib/myLaws/SeparationLaw.hpp"
#include "../lib/myLaws/CohesionLaw.hpp"
#include "../lib/myLaws/AlignmentLaw.hpp"


class Bird {
private:
	// Use an ID attribute?
	Vec2 m_position;
	Vec2 m_velocity;
	Vec2 m_nextVelocity;
	Vec2 m_nextPosition; // A copier dans velocity
	double m_bodySize;

	CohesionLaw m_cohesionLaw;// = CohesionLaw{};
	SeparationLaw m_separationLaw;// = SeparationLaw{};
	AlignmentLaw m_AlignmentLaw;

public:
	Bird(); // Constructeur sans arguments
	//Bird(const Bird& other);
	Bird(const Vec2& position, const Vec2& velocity);
	//~Bird(); // Destructeur


public:
	Vec2 getPosition() const;
	Vec2 getVelocity() const;

	void updateVelocity(const std::vector<Bird>& neighbors);
	void computePosition();
	void updatePosition();
	void escape();
	Vec2 getNextPosition() const;
	Vec2 getNextVelocity() const;
	void setNextPosition(Vec2 nextPosition);
	void print() const;


	//Need to change
	Vec2 alignment(const std::vector<Bird>& neighbors) { return {}; };

};