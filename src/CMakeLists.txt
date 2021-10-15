FIND_PACKAGE(glfw3 3.3 REQUIRED) # REQUIRED means : "fatal if not found"
FIND_PACKAGE(glad REQUIRED)
FIND_PACKAGE(OpenCV REQUIRED)

add_library(libGLX "resources/graphics/glx.cpp" "resources/graphics/glx.hpp" "resources/graphics/GraphicalManager.hpp" "resources/graphics/GraphicalManager.cpp" "resources/graphics/graphics.hpp" "resources/graphics/graphics.cpp" "resources/graphics/oglTypes.hpp")
target_link_libraries(libGLX PUBLIC glfw::glfw glad::glad opencv::opencv)

add_subdirectory("lib/myLaws")
add_subdirectory("lib/myMath")
add_subdirectory("resources")
add_subdirectory("resources/graphics")

add_executable(mathPart math_main.cpp)
target_link_libraries(mathPart PUBLIC myMath)


add_subdirectory("resources/graphics/shaders")

add_executable(graphicsTest graphics_main.cpp)
target_link_libraries(graphicsTest PUBLIC libGLX myMath shaders)

add_executable(life-of-boids main.cpp)
target_link_libraries(life-of-boids PUBLIC libGLX myMath shaders myBirds myLaws)

add_executable(main_opencv main_opencv.cpp)
target_link_libraries(main_opencv PRIVATE opencv::opencv)
