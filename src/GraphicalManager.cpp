#include <iostream>
#include "glx.hpp"
#include "shaders/lines.hpp"
#include "shaders/points.hpp"
#include "shaders/triangle.hpp"
#include "GraphicalManager.hpp"
#include "graphics.hpp"


GraphicalManager::GraphicalManager() {
    std::cout << "Constructing GraphicalManager object" << std::endl;
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    // Specifying some OpenGL variables
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Triangle", nullptr, nullptr);

    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);
    gladLoadGL();
    glfwSwapInterval(1);

    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
}


GraphicalManager::GraphicalManager(float width, float height) {
    std::cout << "Constructing GraphicalManager object" << std::endl;
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    // Specifying some OpenGL variables
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height, "OpenGL Triangle", nullptr, nullptr);

    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);
    gladLoadGL();
    glfwSwapInterval(1);

    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
}

GraphicalManager::~GraphicalManager() {
    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);
}

int GraphicalManager::mainLoop() {

    while (!glfwWindowShouldClose(window)) {
        // Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw nothing, see you in tutorial 2 !


        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}

/** Prints the error number and description
  *
  * @param error Error ID.
  * @param description Error text description.
  */
static void error_callback(int error, const char* description) {
    std::cerr << "Error[" << error << "]: " << description << "\n";
}

/** Actions to be taken when specific keys are pressed
  *
  * @param window our window
  * @param key which key
  * @param scancode
  * @param action action taken (press, unpress, repeat...)
  */
static void key_callback(GLFWwindow* window, int key, int /*scancode*/, int action, int /*mods*/) {
    // If the user presses (GLFW_PRESS) escape key (GLFW_KEY_ESCAPE)
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        // Sets the window into "closing mode"
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    if (key == GLFW_KEY_S && action == GLFW_PRESS) {
        std::puts("Export current display");
        char export_filename[] = "export.png";
        saveImage(export_filename, window);
    }
}