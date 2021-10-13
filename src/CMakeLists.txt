FIND_PACKAGE(glfw3 3.3 REQUIRED) # REQUIRED means : "fatal if not found"
FIND_PACKAGE(glad REQUIRED)
FIND_PACKAGE(OpenCV REQUIRED)

add_library(libGLX glx.cpp glx.hpp)
target_link_libraries(libGLX PUBLIC glfw::glfw glad::glad opencv::opencv)

add_subdirectory("lib/myLaws")
add_subdirectory("lib/myMath")
add_subdirectory("resources")

add_executable(MathPart math_main.cpp)
target_link_libraries(MathPart PUBLIC myMath)


add_subdirectory(shaders)

add_executable(GraphicsTest graphics_main.cpp "graphics.hpp" "graphics.cpp" "GraphicalManager.hpp" "GraphicalManager.cpp" "oglTypes.hpp")
target_link_libraries(GraphicsTest PUBLIC libGLX myMath shaders)

add_executable(life-of-boids main.cpp "GraphicalManager.hpp" "GraphicalManager.cpp" "graphics.hpp" "graphics.cpp" "oglTypes.hpp")
target_link_libraries(life-of-boids PUBLIC libGLX myMath shaders myBirds)

add_executable(main_opencv main_opencv.cpp)
target_link_libraries(main_opencv PRIVATE opencv::opencv)



