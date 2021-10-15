#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>
#include <string>


#include "lib/myMath/Vec2.hpp"
#include "lib/myMath/utils.hpp"
#include "resources/Flock.hpp"
#include "resources/graphics/glx.hpp"
#include "resources/graphics/graphics.hpp"
#include "resources/graphics/GraphicalManager.hpp"
#include "resources/graphics/oglTypes.hpp"


Flock* flockPtr = nullptr;


int main() {

    GraphicalManager GM{};

    for (int i = 0; i < 10; ++i) {
        randomVec2Generation(0, 600);
    }
        
    Flock flock{5};
    flockPtr = &flock;
    //Bird titi(Vec2(400, 400), Vec2(0.2, 0.2));
    //flock.addAgent(titi);
    //Bird toto(Vec2(200, 400), Vec2(-0.2, 0.2));
    //flock.addAgent(toto);


    float t = 0;
    bool shouldClose = false;
    while (t == 0) {
        (*flockPtr).print();
        shouldClose = GM.mainLoop(t);
        ++t;
        std::cout << "Tour " << (int)t << "-----------------------------" << '\n';
        (*flockPtr).print();
    }
}

