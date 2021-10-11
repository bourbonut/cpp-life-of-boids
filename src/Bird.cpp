#include "Bird.hpp"

Bird::Bird() {}
Bird::Bird(const vec2 &position, const vec2 &velocity){
	this->position = position;
	this->velocity = velocity;
}
Bird::~Bird(){}

vec2 Bird::cohesion(const std::vector<Bird> &neighbors) {

	//We get the barycenter of all the neighbors
	vec2 barycenter = computeAgentsBarycenter(neighbors);

	//we calculate the coordinates of the velocity vector
	//we want to use barycenter.x, or even barycenter - this.position 
	vec2 newVelocity = { barycenter[0] - this->position[0], barycenter[1] - this->position[1] };

	return newVelocity;
}

//vec2 Bird::computeBarycenter(const std::vector<vec2>& points) {
//	vec2 result = {0, 0};
//	return result;
//}

vec2 Bird::computeAgentsBarycenter(const std::vector<Bird>& neighbors) {
	
	//const std::size_t nbNeighbors = neighbors.size();
	
	//We create a new array with a size of the number of neighbors
	std::vector<vec2> points(neighbors.size());

	for (int i = 0; i < neighbors.size(); ++i) {
		//filling the array with the coordinates of the position of each agent of the neighborhood
		points[i] = { (((Bird)neighbors[i]).getPosition())[0], (((Bird)neighbors[i]).getPosition())[1] };
	}

	return computeBarycenter(points);
}

std::vector<vec2> Bird::getCoordinatesArray(const std::vector<Bird>& neighbors) {
	//We create a new array with a size of the number of neighbors
	std::vector<vec2> points(neighbors.size());

	for (int i = 0; i < neighbors.size(); ++i) {
		//filling the array with the coordinates of the position of each agent of the neighborhood
		points[i] = { (((Bird)neighbors[i]).getPosition())[0], (((Bird)neighbors[i]).getPosition())[1] };
	}

	return points;
}



vec2 Bird::getPosition() { return this->position; }
vec2 Bird::getVelocity() { return this->velocity; }

