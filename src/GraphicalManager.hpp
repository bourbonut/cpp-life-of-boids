#pragma once

#include "glx.hpp"
#include "shaders/lines.hpp"
#include "shaders/points.hpp"
#include "shaders/triangle.hpp"


class GraphicalManager {
private:
	GLFWwindow* window;

public:
	GraphicalManager();
	GraphicalManager(float, float);
	~GraphicalManager();

	int mainLoop();
};


static void error_callback(int error, const char* description);

static void key_callback(GLFWwindow* window, int key, int /*scancode*/, int action, int /*mods*/);

