#include <iostream>
#include <chrono>
#include <tuple>
#include <vector>
#include <utility>
#include <unordered_map>
#include "resources/model/Flock.hpp"
#include "resources/model/Bird.hpp"
#include "resources/model/Eagle.hpp"
#include "resources/controller/flock_generator.hpp"

using tupleXYID = std::tuple<float, float, int>;
using tupleNP = std::tuple<std::vector<Agent*>, std::vector<Agent*>>;
using pair = std::pair<Vec2, Agent*>;
using dict = std::unordered_map<int, std::vector<pair>>;

using namespace std::chrono;

struct {
  bool operator()(tupleXYID a, tupleXYID b) const { return std::get<2>(a) < std::get<2>(b); }
} customLessIndex;

template<class InputIt1, class InputIt2, class OutputIt, class Compare>
OutputIt set_intersection(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt d_first, Compare comp)
{
    while (first1 != last1 && first2 != last2) {
        if (comp(*first1, *first2)) {
            ++first1;
        } else {
            if (!comp(*first2, *first1)) {
                *d_first++ = *first1++;
            }
            ++first2;
        }
    }
    return d_first;
}

void updateAll(const float& w, const float& h, dict* grid, const std::vector<Agent*>& agents){
  for(Agent* a: agents){
    Vec2 pos = (*a).getPosition();
    Vec2 normalized_pos = pos + Vec2(w, h);
    int i = (int)(normalized_pos.x / 50);
    int j = (int)(normalized_pos.y / 50);
    // std::cout << "i j : " << i << " " << j << '\n';
    // std::cout << "i * i + j : " << i * i + j << " and " << pos << '\n';
    (*grid)[i * i + j].push_back(std::make_pair(pos, a));
  }
}


int main(int argc, char* argv[]) {
  try{
    Flock flock = generate_flock_with_args(argc, argv);

    if (flock.getPopSize() > 700) {
      flock.optimized_computing = true;
      flock.setOptimization();
    }
    float width = 1000.;
    float height = 850.;

    dict grid;

    for(int t=0; t<5; t++){
      std::cout << "t = " << t << '\n';
      auto start = high_resolution_clock::now();
      updateAll(width, height, &grid, flock.m_agents);
      for (Agent* bird : flock){
        Vec2 pos = (*bird).getPosition();
        double range = (*bird).getRange();
        int id = (*bird)._id;
        Vec2 normalized_pos = pos + Vec2(width, height);
        int i = (int)(normalized_pos.x / 50);
        int j = (int)(normalized_pos.y / 50);
        std::vector<pair> potentialNeighbors;
        std::vector<pair>* ptr = &grid[i * i + j];
        potentialNeighbors.insert(potentialNeighbors.begin(), (*ptr).begin(), (*ptr).end());
        ptr = &grid[(i - 1) * (i - 1) + j];
        potentialNeighbors.insert(potentialNeighbors.end(), (*ptr).begin(), (*ptr).end());
        ptr = &grid[(i + 1) * (i + 1) + j];
        potentialNeighbors.insert(potentialNeighbors.end(), (*ptr).begin(), (*ptr).end());
        ptr = &grid[i * i + j - 1];
        potentialNeighbors.insert(potentialNeighbors.end(), (*ptr).begin(), (*ptr).end());
        ptr = &grid[(i - 1) * (i - 1) + j - 1];
        potentialNeighbors.insert(potentialNeighbors.end(), (*ptr).begin(), (*ptr).end());
        ptr = &grid[(i + 1) * (i + 1) + j - 1];
        potentialNeighbors.insert(potentialNeighbors.end(), (*ptr).begin(), (*ptr).end());
        ptr = &grid[i * i + j + 1];
        potentialNeighbors.insert(potentialNeighbors.end(), (*ptr).begin(), (*ptr).end());
        ptr = &grid[(i + 1) * (i + 1) + j + 1];
        potentialNeighbors.insert(potentialNeighbors.end(), (*ptr).begin(), (*ptr).end());
        ptr = &grid[(i - 1) * (i - 1) + j + 1];
        potentialNeighbors.insert(potentialNeighbors.end(), (*ptr).begin(), (*ptr).end());

        float angle;
      	std::vector<Agent*> neighbors;
      	std::vector<Agent*> neighborsPredators;
      	neighbors.reserve(potentialNeighbors.size());
        for (pair data : potentialNeighbors) {
          Vec2 neighbor = std::get<0>(data);
          angle = degrees((pos - neighbor).angle());
          if (!(angle > range * 0.5)){
      			if (distance(pos, neighbor) <= range){
              Agent* potentialNeighbor = std::get<1>(data);
              if(!(id == (*potentialNeighbor)._id)){
                if (dynamic_cast<Bird*> (potentialNeighbor) != nullptr) {
        					neighbors.push_back(potentialNeighbor);
        				}
        				else if (dynamic_cast<Eagle*> (potentialNeighbor) != nullptr) {
        					neighborsPredators.push_back(potentialNeighbor);
        				}
              }
      			}
      		}
      	}
        // tupleNP allNeighbors = std::make_tuple( neighbors, neighborsPredators );
        // tupleNP origin = flock.computeNeighborsOrigin(*bird);
        //
        // if(std::get<0>(allNeighbors).size() != std::get<0>(origin).size()){
        //   std::cout << "error" << '\n';
        // }
      //   std::vector<Agent*> bVec = std::get<0>(allNeighbors);
      //   std::vector<Agent*> eVec = std::get<1>(allNeighbors);
      //
      //
      //   (*bird).computeLaws(bVec, eVec);
      //   (*bird).prepareMove();
      // }
      // for (Agent* bird : flock){
      //   (*bird).keepPositionInScreen(width, height);
      //   (*bird).move();
      }
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<milliseconds>(stop - start);
      std::cout << "Time : " << duration.count() << " ms" << '\n';
      std::cout << "FPS : " << 1 / (duration.count()*1e-3) << '\n';
      grid.clear();
    }
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}
