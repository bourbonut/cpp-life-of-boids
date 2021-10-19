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


Flock* MAIN_pFLOCK= nullptr;
std::vector<Agent*> mainFlock;

int main() {


    
    //Need to do like this because we are using ptr fir the birds in the flock
    int size = 400;

    mainFlock.reserve(size);
    for (int i = 0; i < size; ++i) {
        mainFlock.push_back(new Bird{});
    }
    Flock flock{ mainFlock };

    GraphicalManager GM{ Color::Default, Color::Default};
    MAIN_pFLOCK = &flock;

    
    float t = 0;
    bool shouldClose = false;
    do {
        shouldClose = GM.mainLoop();
        ++t;
    } while (!shouldClose);
}

