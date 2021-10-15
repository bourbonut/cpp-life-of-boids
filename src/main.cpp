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
#include <chrono>
#include <string>
#include "resources/Flock.hpp"


#include "resources/graphics/glx.hpp"
#include "resources/graphics/graphics.hpp"
#include "resources/graphics/GraphicalManager.hpp"
#include "resources/graphics/oglTypes.hpp"


int main() {

    GraphicalManager GM{};


    Flock flock{};
    Bird titi(Vec2(400, 400), Vec2(0.2, 0.2));
    flock.addAgent(titi);
    Bird toto(Vec2(200, 400), Vec2(-0.2, 0.2));
    flock.addAgent(toto);


    float t = 0;
    bool shouldClose = false;
    while (!shouldClose) {
        shouldClose = GM.mainLoop(t, flock);
        ++t;

    }


}
