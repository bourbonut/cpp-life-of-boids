FIND_PACKAGE(glfw3 3.3 REQUIRED) # REQUIRED means : "fatal if not found"
FIND_PACKAGE(glad REQUIRED)
FIND_PACKAGE(OpenCV REQUIRED)
FIND_PACKAGE(TBB REQUIRED)

add_subdirectory("lib/myLaws")
add_subdirectory("lib/myMath")
add_subdirectory("resources/graphics")
add_subdirectory("resources/model")
add_subdirectory("resources/controller")
add_subdirectory("resources/graphics/shaders")

add_executable(mathPart math_main.cpp)
target_link_libraries(mathPart PUBLIC myMath)

add_executable(life-of-boids main.cpp)
target_link_libraries(life-of-boids PUBLIC libGLX myMath shaders myBirds myLaws opencv::opencv TBB::TBB flockGenerator)

add_executable(chrono main_chrono.cpp)
target_link_libraries(chrono PUBLIC libGLX myMath shaders myBirds myLaws opencv::opencv TBB::TBB flockGenerator)
