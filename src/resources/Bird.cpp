#include "Bird.hpp"

#include <array>
#include <vector>
#include "../lib/myMath/Vec2.hpp"
#include "../lib/myMath/utils.hpp"

//Bird::Bird() = default;
//Bird::Bird(Vec2 &position, Vec2 &velocity){
//	m_position = Vec2(position);
//	m_velocity = Vec2(velocity);
//}
Bird::~Bird(){}

Bird::Bird(const Vec2 &position, const Vec2 &velocity) : m_position{ position }, m_velocity{ velocity },
										   m_nextPosition{ position }, m_nextVelocity{velocity} {};

Bird::Bird() {
	m_position = Vec2(0, 0);
	m_velocity = Vec2(1, 1);
	m_nextPosition = Vec2(0, 0);
	m_nextVelocity = Vec2(1, 1);
};

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

void Bird::updateVelocity(const std::vector<Bird> &neighbors) {
	Vec2 vecCohesion = this->cohesion(neighbors);
	Vec2 vecAlignment = this->alignment(neighbors);
	Vec2 vecSeparation = this->separation(neighbors);
	Vec2 vec_displacement = vecCohesion + vecAlignment + vecSeparation;
	m_nextVelocity = m_velocity + vec_displacement;
};

void Bird::computePosition() {
	m_nextPosition = m_position + m_nextVelocity;
};

void Bird::updatePosition() {
	m_position = m_nextPosition;
	m_velocity = m_nextVelocity;
};

Vec2 Bird::cohesion(const std::vector<Bird> &neighbors) {

	//We get the barycenter of all the VALID neighbors
	Vec2 barycenter = computeAgentsBarycenter(neighbors);

	//We calculate the coordinates of the velocity vector
	//We want to use barycenter.x, or even barycenter - this.position
	Vec2 newVelocity = { barycenter.x - m_position.x, barycenter.y - m_position.y };

	return newVelocity;
}

Vec2 Bird::separation(const std::vector<Bird>& neighbors)
{
	Vec2 result;
	float distBetwA = 0, weight = 0;

	//for each neighbor bird, add to a final vector the weigthed input of the neighbor bird
	for(Bird b : neighbors)
	{
		distBetwA = distance(b.getPosition(), m_position);
		//Get the weight from the inverse of the square, depending on the distance between the two agents
		weight = 1 / ((distBetwA / m_SEPARATION_RANGE) * (distBetwA / m_SEPARATION_RANGE));
		//Calculates a vector between agent b and this, and mutiplies it by the current weight of agent b
		result = result + (m_position - b.getPosition()) * weight;
	}

	//divide the actual final vector by the number of neighbor birds to get a final vector pointing to the barycenter needed
	result = result / neighbors.size();

	return result;
}

Vec2 Bird::computeAgentsBarycenter(const std::vector<Bird> &neighbors) {

	//We create a new array with a size of the number of neighbors
	std::vector<Vec2> points(neighbors.size());
	points = getCoordinatesArray(neighbors);

	return barycenter(points);
}

std::vector<Vec2> Bird::getCoordinatesArray(const std::vector<Bird> &neighbors) {
	//We create a new array with a size of the number of neighbors
	std::vector<Vec2> points(neighbors.size());

	for (int i = 0; i < neighbors.size(); ++i) {
		//filling the array with the coordinates of the position of each agent of the neighborhood
		float x = (neighbors[i]).getPosition().x;
		float y = (neighbors[i]).getPosition().y;
		points[i] = Vec2(x, y);
		//points[i] = { (((Bird)neighbors[i]).getPosition())[0], (((Bird)neighbors[i]).getPosition())[1] };
	}

	return points;
}
