#include "Bird.hpp"

#include <array>
#include <vector>
#include "../lib/myMath/Vec2.hpp"
#include "../lib/myMath/utils.hpp"


//Bird::~Bird() {};
Bird::Bird() {
	Vec2 pos = randomVec2Generation(0, 1000);
	Vec2 vel = randomVec2Generation(-5, 5);
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

void Bird::setNextPosition(Vec2 nextPosition) {
	m_nextPosition = nextPosition;
}


void Bird::updateVelocity(const std::vector<Bird>& neighbors) {
	Vec2 vecCohesion = m_cohesionLaw.compute(*this, neighbors) ;
	Vec2 vecAlignment = m_AlignmentLaw.compute(*this, neighbors);
	Vec2 vecSeparation = m_separationLaw.compute(*this, neighbors);
	Vec2 vec_displacement = vecCohesion *0.2 + vecAlignment + vecSeparation;
	m_nextVelocity = vec_displacement.normalize() * 0.2; // To go real slow to show client
};

void Bird::computePosition() {
	m_nextPosition = m_position + m_nextVelocity;

	//TO CHANGE !!! ONLY TO SHOW SMHT TO CLIENT
	//m_nextVelocity += randomVec2Generation(-1, 1);//.normalize(); //Test to randomly move birds
	//m_nextVelocity.normalize();
};

void Bird::updatePosition() {
	m_position = m_nextPosition;
	m_velocity = m_nextVelocity;
};


void Bird::print() const {
	std::cout << ">>>Printing bird : P(" << m_position.x << ", " << m_position.y << " ) / V(" << m_velocity.x << ", " << m_velocity.y << " )";
	std::cout << "\n>>>           N_P( " << m_nextPosition.x << ", " << m_nextPosition.y << " ) / N_V(" << m_nextVelocity.x << ", " << m_nextVelocity.y << " )\n";
};
