#include "Bird.hpp"

#include <array>
#include <vector>
#include "../lib/myMath/Vec2.hpp"
#include "../lib/myMath/utils.hpp"


//Bird::~Bird() {};
Bird::Bird() {
	Vec2 pos = randomVec2Generation(0, 1000);
	Vec2 vel = randomVec2Generation(-1, 1);
	m_position = pos;
	m_velocity = vel;
	m_nextPosition = pos + 1;
	m_nextVelocity = vel + 1;
};
//NEED CTOR BY COPY (rule of three) BUT ACCESSING TO OTHER BIRD'S DATA SEEMS WEIRD
//MAYBE WE NEED A STRUCT ?? OR MAYBE WE NEED TO APPLY THE ZERO LAW AND BIRDS ARE NOT THE ONES WHO RANDOMIZE!!
//Bird::Bird(const Bird& other) {};

Bird::Bird(const Vec2& position, const Vec2& velocity) : m_position{ position }, m_velocity{ velocity },
m_nextPosition{ position }, m_nextVelocity{ velocity }, m_bodySize{ 1 } {};



Vec2 Bird::getPosition() const {
	return m_position;
};

Vec2 Bird::getVelocity() const {
	return m_velocity;
};

Vec2 Bird::getNextPosition() const {
	return m_nextPosition;
};

Vec2 Bird::getNextVelocity() const {
	return m_nextVelocity;
};


void Bird::updateVelocity(const std::vector<Bird>& neighbors) {
	Vec2 vecCohesion = m_cohesionLaw.compute(*this, neighbors);
	Vec2 vecAlignment = m_AlignmentLaw.compute(*this, neighbors);
	Vec2 vecSeparation = m_separationLaw.compute(*this, neighbors);
	Vec2 vec_displacement = vecCohesion / 10 + vecAlignment + vecSeparation * 1000;
	m_nextVelocity = vec_displacement.normalize() * 0.5; // To go real slow to show client, normal : 0.5 + .normalize()
};

void Bird::computePosition() {
	m_nextPosition = m_position + m_nextVelocity;

	if (m_position.x - 0.5 < m_nextPosition.x < m_position.x + 0.5)
	{
		m_nextPosition.x = m_nextPosition.x + 0.1;
	}
	if (m_position.y - 0.5 < m_nextPosition.y < m_position.y + 0.5)
	{
		m_nextPosition.y = m_nextPosition.y + 0.1;
	}

	//TO CHANGE !!! ONLY TO SHOW SMHT TO CLIENT
	//m_nextVelocity += randomVec2Generation(-1, 1);//.normalize(); //Test to randomly move birds
	//m_nextVelocity.normalize();
};

void Bird::updatePosition() {
	m_position = m_nextPosition;
	m_velocity = m_nextVelocity;
};

void Bird::escape() {

};


void Bird::print() const {
	std::cout << ">>>Printing bird : P(" << m_position.x << ", " << m_position.y << " ) / V(" << m_velocity.x << ", " << m_velocity.y << " )";
	std::cout << "\n>>>           N_P( " << m_nextPosition.x << ", " << m_nextPosition.y << " ) / N_V(" << m_nextVelocity.x << ", " << m_nextVelocity.y << " )\n";
};
