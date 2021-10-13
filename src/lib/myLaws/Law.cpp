//#include "Law.hpp"
//#include "../myMath/Vec2.hpp"
//#include "../myMath/utils.hpp"

////Return an array of Vec2 based on an array of Birds
//std::vector<Vec2> getCoordinatesArray(const std::vector<Bird>& neighbors) {
//	//We create a new array with a size of the number of neighbors
//	std::vector<Vec2> points(neighbors.size());
//
//	for (int i = 0; i < neighbors.size(); ++i) {
//		//filling the array with the coordinates of the position of each agent of the neighborhood
//		float x = (neighbors[i]).getPosition().x;
//		float y = (neighbors[i]).getPosition().y;
//		points[i] = Vec2{ x, y };
//		//points[i] = { (((Bird)neighbors[i]).getPosition())[0], (((Bird)neighbors[i]).getPosition())[1] };
//	}
//
//	return points;
//};
//
////Get the barycenter of a bunch of agents
//Vec2 computeAgentsBarycenter(const std::vector<Bird>& neighbors) {
//
//	//We create a new array with a size of the number of neighbors
//	std::vector<Vec2> points(neighbors.size());
//	points = getCoordinatesArray(neighbors);
//
//	return barycenter(points);
//};


