#include <iostream>
#include "resources/model/Flock.hpp"
#include "resources/graphics/GraphicalManager.hpp"
#include "resources/controller/flock_generator.hpp"
Flock* MAIN_pFLOCK = nullptr;

int main(int argc, char* argv[]) {

	try
	{
		Flock flock = generate_flock_with_args(argc, argv);

		bool fullScreen = false;
		GraphicalManager GM{ Color::BlueGrey, fullScreen };

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
