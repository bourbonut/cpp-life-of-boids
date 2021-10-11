FIND_PACKAGE(glfw3 3.3 REQUIRED) # REQUIRED means : "fatal if not found"
FIND_PACKAGE(glad REQUIRED)
FIND_PACKAGE(OpenCV REQUIRED)

add_library(libGLX glx.cpp glx.hpp "Bird.cpp" "Bird.hpp" "Flock.cpp" "Flock.hpp")
target_link_libraries(libGLX PUBLIC glfw::glfw glad::glad opencv::opencv)

add_subdirectory(myMath)
#add_executable(MathPart math_main.cpp)
#target_link_libraries(MathPart PUBLIC myMath)

add_executable(life-of-boids main.cpp "Bird.cpp" "Bird.hpp" "Flock.cpp" "Flock.hpp")
target_link_libraries(life-of-boids PUBLIC libGLX myMath)

add_executable(main_opencv main_opencv.cpp)
target_link_libraries(main_opencv PRIVATE opencv::opencv)

