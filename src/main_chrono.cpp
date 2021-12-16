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



int main(int /*argc*/, char** /*argv[]*/) {
  try{
    float width = 1000.;
    float height = 850.;

    std::vector<int> sizes {4096, 8192, 16384};//, 32768, 65536, 131072};
    std::vector<int> vthreads {1, 2, 4, 8};
    std::vector<bool> vswitch {false, true};

    // for(int t=0; t<5; t++){
    for(int size : sizes){
      std::cout << "size : " << size << '\n' << '\n';
      for(bool switch_ : vswitch){
        if(switch_){
          std::cout << "TBB :" << '\n' << '\n';
        }
        else{
          std::cout << "OpenMP :" << '\n' << '\n';
        }
        for(int threads : vthreads){
          Flock flock = generate_parrot_flock(size); // generate_flock_with_args(argc, argv);
          auto start = high_resolution_clock::now();
          flock.experiment(true, width, height, threads, switch_);
          auto stop = high_resolution_clock::now();
          auto duration = duration_cast<milliseconds>(stop - start);
          std::cout << "Time : " << duration.count() << " ms" << '\n';
          // std::cout << "FPS : " << 1 / (duration.count()*1e-3) << '\n';
        }
        std::cout << '\n';
      }
    }
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}
