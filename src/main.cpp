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
#include "resources/controller/flock_generator.hpp"


Flock* MAIN_pFLOCK= nullptr;
std::vector<Agent*> mainFlock;

int main() {

    int size = 600;
    mainFlock.reserve(size);


    //Flock flock = generate_dove_flock(size);
    Flock flock = generate_parrot_flock(size);
    //Flock flock = generate_duck_flock(size);
    //Flock flock = create_bird_flock(size, Color::Blue, 3, 50, 180, Vec2{ 0,0 }, Vec2{ 1,1 });
    //Flock flock = generate_fully_random_bird_flock();
    //Flock flock = generate_ant_flock(size);
    //Flock flock = generate_fly_flock(size);

    bool fullScreen = false;
    GraphicalManager GM{ Color::BlueGrey, fullScreen};
    MAIN_pFLOCK = &flock;

    float t = 0;
    bool shouldClose = false;
    do {
        shouldClose = GM.mainLoop();
        ++t;
    } while (!shouldClose);
}

