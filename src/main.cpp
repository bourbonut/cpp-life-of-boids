#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>


#include "glx.hpp"
#include "myMath/Vec2.hpp"
#include "graphics.hpp"
#include "GraphicalManager.hpp"
#include "oglTypes.hpp"


int main() {

    GraphicalManager GM{};
    GM.mainLoop();

}
