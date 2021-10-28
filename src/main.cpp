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


Flock* MAIN_pFLOCK = nullptr;

int main(int argc, char* argv[]) {

	try
	{
		Flock flock = generate_flock_with_args(argc, argv);

		bool fullScreen = false;
		GraphicalManager GM{ Color::BlueGrey, fullScreen };

		if (flock.getPopSize() > 700) {
			flock.optimized_computing = true;
			std::cout << "Size of flock over 700, using the optimized version of compute neighbors.\nIf you want to use predator, you might prefer generating a small flock (size under 700)." << std::endl;
		}

		MAIN_pFLOCK = &flock;

		float t = 0;
		bool shouldClose = false;
		do {
			shouldClose = GM.mainLoop();
			++t;
		} while (!shouldClose);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;

}
