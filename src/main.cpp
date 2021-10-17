#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

#include "lib/myMath/Vec2.hpp"
#include "lib/myMath/utils.hpp"
#include "resources/model/Flock.hpp"
#include "resources/graphics/glx.hpp"
#include "resources/graphics/graphics.hpp"
#include "resources/graphics/GraphicalManager.hpp"
#include "resources/graphics/oglTypes.hpp"


Flock* flockPtr = nullptr;
std::vector<Agent*> mainFlock;

int main() {

    GraphicalManager GM{};
    
    int size = 400;

    mainFlock.reserve(size);
    for (int i = 0; i < size; ++i) {
        //Bird b = Bird{};
        mainFlock.push_back(new Bird{});
    }
    Flock flock{ mainFlock };
    flockPtr = &flock;
    //Bird titi(Vec2(400, 400), Vec2(0.2, 0.2));
    //flock.addAgent(titi);
    //Bird toto(Vec2(200, 400), Vec2(-0.2, 0.2));
    //flock.addAgent(toto);


    float t = 0;
    bool shouldClose = false;
    while (!shouldClose) {
        shouldClose = GM.mainLoop(t);
        ++t;

    }
}

