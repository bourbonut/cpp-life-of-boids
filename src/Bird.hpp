#pragma once

class Bird {
private:
	vec2 m_position;
	vec2 m_velocity;
	vec2 m_nextVelocity; // A copier dans velocity
	double m_bodySize = 1;
	double m_viewAngle;
	double m_COHESION_RANGE;
	double m_NEIGHBOR_RANGE;
	double m_SEPARATION_RANGE;
	double m_ALIGNMENT_RELAXATION;
	double m_COHESION_RELAXATION;

	std::vector<Bird> m_neighbors;

public:
	Bird(); // Constructeur avec argument par défaut
	Bird(vec2 m_position, vec2 m_velocity);
	~Bird(); // Destructeur

public:
	vec2 getPosition();
	vec2 getVelocity();

	std::vector<Bird> computeNeighbors();
	vec2 m_vec_cohesion = cohesion(neighbors);
	vec2 m_vec_alignment = alignment(neighbors);
	vec2 m_vec_separation = separation(neighbors);
	void updateVelocity(m_vec_cohesion, m_vec_alignment, m_vec_separation);
	void updatePosition()
};


