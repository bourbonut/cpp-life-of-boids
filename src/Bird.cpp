#include "Bird.hpp"

#include <array>
#include <vector>
#include "myMath/Vec2.hpp"
// #include "myMath/utils.hpp"
Bird::Bird() {}
Bird::Bird(const Vec2 &position, const Vec2 &velocity){
	this->position = position;
	this->velocity = velocity;
}
Bird::~Bird(){}

void Bird::updateVelocity(const std::vector<Bird> &neighbors) {
	Vec2 vecCohesion = cohesion(neighbors);
	Vec2 vecAlignment = alignment(neighbors);
	Vec2 vecSeparation = separation(neighbors);
	Vec2 vec_displacement = vecCohesion + vecAlignment + vecSeparation;
	m_velocity = m_velocity + vec_displacement;
};

void Bird::updatePosition() {
	m_position = m_position + m_velocity;
};

Vec2 Bird::cohesion(const std::vector<Bird> &neighbors) {

	//We get the barycenter of all the neighbors
	vec2 barycenter = computeAgentsBarycenter(neighbors);

	//we calculate the coordinates of the velocity vector
	//we want to use barycenter.x, or even barycenter - this.position 
	Vec2 newVelocity = { barycenter[0] - this->position[0], barycenter[1] - this->position[1] };

	return newVelocity;
}

//vec2 Bird::computeBarycenter(const std::vector<vec2>& points) {
//	vec2 result = {0, 0};
//	return result;
//}

Vec2 Bird::computeAgentsBarycenter(const std::vector<Bird>& neighbors) {
	
	//const std::size_t nbNeighbors = neighbors.size();
	
	//We create a new array with a size of the number of neighbors
	std::vector<Vec2> points(neighbors.size());

	for (int i = 0; i < neighbors.size(); ++i) {
		//filling the array with the coordinates of the position of each agent of the neighborhood
		points[i] = { (((Bird)neighbors[i]).getPosition())[0], (((Bird)neighbors[i]).getPosition())[1] };
	}

	return computeBarycenter(points);
}

Vec2 Bird::getCoordinatesArray(const std::vector<Bird>& neighbors) {
	//We create a new array with a size of the number of neighbors
	std::vector<vec2> points(neighbors.size());

	for (int i = 0; i < neighbors.size(); ++i) {
		//filling the array with the coordinates of the position of each agent of the neighborhood
		points[i] = { (((Bird)neighbors[i]).getPosition())[0], (((Bird)neighbors[i]).getPosition())[1] };
	}

	return points;
}



Vec2 Bird::getPosition() { return this->position; }
Vec2 Bird::getVelocity() { return this->velocity; }

