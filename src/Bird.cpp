#include "Bird.hpp"

#include <array>
#include <vector>
#include "myMath/Vec2.hpp"
#include "myMath/utils.hpp"

Bird::Bird() {}
Bird::Bird(Vec2 &position, Vec2 &velocity){
	m_position = Vec2();
	m_position = position;
	m_velocity = Vec2();
	m_velocity = velocity;
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
	Vec2 barycenter = computeAgentsBarycenter(neighbors);

	//we calculate the coordinates of the velocity vector
	//we want to use barycenter.x, or even barycenter - this.position 
	Vec2 newVelocity = { barycenter.x() - m_position.x(), barycenter.y() - m_position.y() };

	return newVelocity;
}

//vec2 Bird::computeBarycenter(const std::vector<vec2>& points) {
//	vec2 result = {0, 0};
//	return result;
//}

Vec2 Bird::computeAgentsBarycenter(const std::vector<Bird> &neighbors) {
	
	//const std::size_t nbNeighbors = neighbors.size();
	
	//We create a new array with a size of the number of neighbors
	std::vector<Vec2> points(neighbors.size());
	points = getCoordinatesArray(neighbors);

	//for (int i = 0; i < neighbors.size(); ++i) {
	//	//filling the array with the coordinates of the position of each agent of the neighborhood
	//	float x = neighbors[i].getPosition().x();
	//	float y = neighbors[i].getPosition().y();
	//	points[i] = Vec2(x, y);
	//	//points[i] = Vec2{ (((Bird)neighbors[i]).getPosition()).x(), (((Bird)neighbors[i]).getPosition()).y() };
	//}

	return barycenter(points);
}

std::vector<Vec2> Bird::getCoordinatesArray(const std::vector<Bird> &neighbors) {
	//We create a new array with a size of the number of neighbors
	std::vector<Vec2> points(neighbors.size());

	for (int i = 0; i < neighbors.size(); ++i) {
		//filling the array with the coordinates of the position of each agent of the neighborhood
		float x = (neighbors[i]).getPosition().x();
		float y = (neighbors[i]).getPosition().y();
		points[i] = Vec2(x, y);		
		//points[i] = { (((Bird)neighbors[i]).getPosition())[0], (((Bird)neighbors[i]).getPosition())[1] };
	}

	return points;
}



Vec2 Bird::getPosition() const { 
	Vec2 pos = Vec2();
	pos = m_position;
	return pos; 
}

Vec2 Bird::getVelocity() const { 
	Vec2 vel = Vec2();
	vel = m_velocity;
	return vel;
}

