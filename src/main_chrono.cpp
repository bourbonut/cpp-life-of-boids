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

// using tupleXYID = std::tuple<float, float, int>;
using tupleNP = std::tuple<std::vector<Agent*>, std::vector<Agent*>>;
using pair = std::pair<Vec2, Agent*>;
using dict = std::unordered_map<int, std::vector<pair>>;

using namespace std::chrono;



int main(int argc, char* argv[]) {
  try{
    Flock flock = generate_flock_with_args(argc, argv);

    float width = 1000.;
    float height = 850.;

    for(int t=0; t<5; t++){
      std::cout << "t = " << t << '\n';
      auto start = high_resolution_clock::now();
      flock.updateAgents(true, width, height);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<milliseconds>(stop - start);
      std::cout << "Time : " << duration.count() << " ms" << '\n';
      std::cout << "FPS : " << 1 / (duration.count()*1e-3) << '\n';
    }
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}
