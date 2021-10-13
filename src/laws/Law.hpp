#pragma once
#include "../myMath/Vec2.hpp"
#include "../Bird.hpp"
//need to add file in CMake.txt

interface Law {
protected :
	float m_range;
	float m_angle;
	float m_relaxation;

public:
	Vec2 compute(Bird currentBird, std::vector<Bird> neighbors);
};

class CohesionLaw : public Law {
	Vec2 compute(Bird currentBird, std::vector<Bird> neighbors) {
		
		return Vec2(); //je veux ovverdie
	}
};

class SeparationLaw : public Law {
	Vec2 compute(Bird currentBird, std::vector<Bird> neighbors) {
		
	}
};

class AlignmentLaw : public Law {
	Vec2 compute(Bird currentBird, std::vector<Bird> neighbors) {
		PosVec2 Boid::alignment(const std::vector<Boid> &neighbors) {
			PosVec2 nextVelocity(0, 0);
			if (neighbors.size() == 0)// || Aigle) {
				return nextVelocity;
			}

			for (int i = 0; i < neighbors.size(); i++) {
				if ((currentBird.getPosition() - neighbors[i]).magnitude() < ALIGNMENT_RADIUS) {
					nextVelocity = getVelocity() + neighbors[i];
				}
			}
			nextVelocity = nextVelocity / (neighbors.size());
			return (nextVelocity - Velocity);
		}

		return Vec2{};
	}
};