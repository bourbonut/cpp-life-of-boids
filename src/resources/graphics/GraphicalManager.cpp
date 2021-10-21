#include <iostream>
#include <vector>
#include <array>
#include "GraphicalManager.hpp"
#include "glx.hpp"
#include "graphics.hpp"

#include "../controller/TriangleDisplayer.hpp"
#include "../controller/DotDisplayer.hpp"

#include "shaders/lines.hpp"
#include "shaders/points.hpp"
#include "shaders/triangle.hpp"
#include <math.h>

#include "../model/Flock.hpp"
#include "../model/Bird.hpp"
#include <string>
#include <iomanip>
#include <chrono>
#include <sstream>

using namespace std::chrono;

//GraphicalManager::GraphicalManager(Color myBackgroundColor, Color myAgentColor, Flock* myFlock) {
//
//};

GraphicalManager::GraphicalManager(Color myBackgroundColor, bool fullScreen) {

    m_background_color = myBackgroundColor;

    std::cout << "Constructing GraphicalManager object" << std::endl;
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    // Specifying some OpenGL variables
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();

    if (fullScreen) {
        m_window = glfwCreateWindow(800, 600, "Life-of-boids", primaryMonitor, nullptr);
    }
    else {
        m_window = glfwCreateWindow(800, 600, "Life-of-boids", nullptr, nullptr);
    }


    if (!m_window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }


    glfwSetKeyCallback(m_window, key_callback);
    glfwSetMouseButtonCallback(m_window, mouse_button_callback);

    glfwMakeContextCurrent(m_window);
    gladLoadGL();
    glfwSwapInterval(1);


    glfwGetFramebufferSize(m_window, &m_width, &m_height);

    //BACKGROUND COLOR
    switch (m_background_color)
    {
    case Color::Red:
        glClearColor(1.f, 0.f, 0.f, 1.0f);
        break;
    case Color::Green:
        glClearColor(0.f, 1.f, 0.f, 1.0f);
        break;
    case Color::Blue:
        glClearColor(0.f, 0.f, 1.f, 1.0f);
        break;
    default:
        glClearColor(0.07f, 0.13f, 0.17f, 1.f);
        break;
    }

    // Points part
    // new
    points_shaderProgram = ShaderProgram_new(points::vertex_shader_text, points::fragment_shader_text);
    points_vertexArray = VertexArray_new();
    points_buffer = Buffer_new();

    VertexArray_bind(points_vertexArray);
    Buffer_bind(points_buffer, GL_ARRAY_BUFFER);
    ShaderProgram_activate(points_shaderProgram);

    m_transform_location = ShaderProgram_getUniformLocation(points_shaderProgram, "transform");
    m_pointSize_location = ShaderProgram_getUniformLocation(points_shaderProgram, "pointSize");
    m_maxSpeedSquared_location = ShaderProgram_getUniformLocation(points_shaderProgram, "maxSpeedSquared");
    m_position_location = ShaderProgram_getAttribLocation(points_shaderProgram, "position");
    m_velocity_location = ShaderProgram_getAttribLocation(points_shaderProgram, "velocity");

    glVertexAttribPointer(
        m_position_location, 2, GL_FLOAT, GL_FALSE, sizeof(points::Vertex), (void*)offsetof(points::Vertex, pos));
    glVertexAttribPointer(
        m_velocity_location, 2, GL_FLOAT, GL_FALSE, sizeof(points::Vertex), (void*)offsetof(points::Vertex, col));

    glEnableVertexAttribArray(m_position_location);
    glEnableVertexAttribArray(m_velocity_location);

    glEnable(GL_PROGRAM_POINT_SIZE);


    // Lines part
    // new
    lines_shaderProgram = ShaderProgram_new(lines::vertex_shader_text, lines::fragment_shader_text);
    lines_vertexArray = VertexArray_new();
    lines_buffer = Buffer_new();
    // init
    VertexArray_bind(lines_vertexArray);
    Buffer_bind(lines_buffer, GL_ARRAY_BUFFER);
    ShaderProgram_activate(lines_shaderProgram);

    m_transform_location2 = ShaderProgram_getUniformLocation(lines_shaderProgram, "transform");
    m_vpos_location2 = ShaderProgram_getAttribLocation(lines_shaderProgram, "vPos");
    m_vcol_location2 = ShaderProgram_getAttribLocation(lines_shaderProgram, "vCol");

    glVertexAttribPointer(
        m_vpos_location2, 2, GL_FLOAT, GL_FALSE, sizeof(triangle::Vertex), (void*)offsetof(triangle::Vertex, pos));
    glVertexAttribPointer(
        m_vcol_location2, 3, GL_FLOAT, GL_FALSE, sizeof(triangle::Vertex), (void*)offsetof(triangle::Vertex, col));

    glEnableVertexAttribArray(m_vpos_location2);
    glEnableVertexAttribArray(m_vcol_location2);
}


GraphicalManager::~GraphicalManager() {
    glfwDestroyWindow(m_window);

    glfwTerminate();
    exit(EXIT_SUCCESS);
}


bool GraphicalManager::mainLoop() {
    TriangleDisplayer triangleDisplay{};
    DotDisplayer dotDisplayer{};

    std::vector<triangle::Vertex> vertex_data_triangle;
    std::vector<points::Vertex> vertex_data_dots;


    if (!glfwWindowShouldClose(m_window)) {
        auto start = high_resolution_clock::now();

        glfwGetFramebufferSize(m_window, &m_width, &m_height);
        const float ratio = m_width / m_height;

        mat3x3 transform = points::vertex_transform_2d(m_width, m_height);

        glViewport(0, 0, m_width, m_height);
        glClear(GL_COLOR_BUFFER_BIT);


        {  // line
            for (auto& bird : *MAIN_pFLOCK) {

                std::vector<Agent*> aVec = (*MAIN_pFLOCK).computeNeighbors(*bird); //this costs performance
                

                (*bird).computeLaws(aVec);
                (*bird).prepareMove();
                (*bird).setNextPosition(keepPositionInScreen((*bird).getNextPosition(), m_width, m_height));
                (*bird).move();


                if (prettyAgents) {
                    // Fill vertex array of groups of 6 points each for double triangles
                    mat2x6 result = triangleDisplay.drawAgent(bird);
                    for (int j = 0; j < result.size(); ++j) {
                        vertex_data_triangle.push_back(triangle::Vertex{ {result[j].x, result[j].y }, (*bird).getGLColor() });
                    }
                }
                else {
                    // Fill vertex array of points for each agents
                    Vec2 res = (dotDisplayer.drawAgent(bird))[0];
                    vertex_data_dots.push_back(points::Vertex{ {res.x, res.y}, (*bird).getGLColor() });
                }
            }


            if (prettyAgents) {
                // DRAW AGENTS AS TRIANGLES
                VertexArray_bind(lines_vertexArray);
                Buffer_bind(lines_buffer, GL_ARRAY_BUFFER);
                ShaderProgram_activate(lines_shaderProgram);

                glUniformMatrix3fv(m_transform_location2, 1, GL_FALSE, (const GLfloat*)&transform);
                glBindVertexArray(lines_vertexArray.vertex_array);
                glBufferData(GL_ARRAY_BUFFER, vertex_data_triangle.size() * sizeof(triangle::Vertex), vertex_data_triangle.data(), GL_STREAM_DRAW);
                glDrawArrays(GL_TRIANGLES, 0, vertex_data_triangle.size());
            }
            else {
                // DRAW AGENTS AS DOTS
                VertexArray_bind(points_vertexArray);
                Buffer_bind(points_buffer, GL_ARRAY_BUFFER);
                ShaderProgram_activate(points_shaderProgram);

                glUniformMatrix3fv(m_transform_location, 1, GL_FALSE, (const GLfloat*)&transform);
                glUniform1f(m_pointSize_location, 3.f);
                glUniform1f(m_maxSpeedSquared_location, 10.f);
                glBindVertexArray(points_vertexArray.vertex_array);

                glBufferData(GL_ARRAY_BUFFER, 0, nullptr, GL_STREAM_DRAW);
                glBufferData(GL_ARRAY_BUFFER, vertex_data_dots.size() * sizeof(points::Vertex), vertex_data_dots.data(), GL_STREAM_DRAW);
                glDrawArrays(GL_POINTS, 0, vertex_data_dots.size());
            }
        }


        //FPS calculations
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        std::ostringstream oss;
        oss << 1 / (duration.count() * 10e-7) << " FPS. " << std::endl;
        glfwSetWindowTitle(m_window, oss.str().c_str());

        // Swap buffers
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    return glfwWindowShouldClose(m_window);
}

std::vector<points::Point> GraphicalManager::createPoints(unsigned int number) {
    std::vector<points::Point> points(number);
    auto get_pos = [=](float t) {
        return Vec2{ (float)(m_width * (0.5 + 0.4 * cos(t))), (float)(m_height * (0.5 + 0.4 * sin(t))) };
    };

    float v = 0;
    for (auto& p : points) {
        v += 1.0;
        p = points::Point{ get_pos(v), Vec2{} };
    }

    return points;
}


/** Prints the error number and description
  *
  * @param error Error ID.
  * @param description Error text description.
  */
static void error_callback(int error, const char* description) {
    std::cerr << "Error[" << error << "]: " << description << "\n";
}

/**
  * Actions to be taken when specific keys are pressed
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
    if (key == GLFW_KEY_UP && action == GLFW_PRESS) {
        std::puts("Touche UP pressee : augmenter le nombre d'oiseaux");
        //(*MAIN_pFLOCK).addAgent();
    }
    if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
        std::puts("Touche DOWN pressee : Diminuer le nombre d'oiseaux");
        //(*MAIN_pFLOCK).destroyAgent();
    }
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
        //change l'affichage de triangles à dots
        prettyAgents = !prettyAgents;
    }
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        if (MAIN_pFLOCK != nullptr) {
            double xpos, ypos;
            //getting cursor position
            glfwGetCursorPos(window, &xpos, &ypos);
            (*MAIN_pFLOCK).addAgent(new Bird{ Vec2{(float)xpos, (float)ypos}, Vec2{2.f,2.f},6, 270,50, Color::Default });
        }
    }
}