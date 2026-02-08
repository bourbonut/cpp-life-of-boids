add_subdirectory("lib/myLaws")
add_subdirectory("lib/myMath")
add_subdirectory("resources/graphics")
add_subdirectory("resources/model")
add_subdirectory("resources/controller")
add_subdirectory("resources/graphics/shaders")

add_executable(mathPart math_main.cpp)
target_link_libraries(mathPart PUBLIC myMath)

set(COMMON_LIBS
  libGLX
  myMath
  shaders
  myBirds
  myLaws
  opencv_core
  opencv_imgcodecs
  tbb
  flockGenerator
  glfw
  glad
  ${OpenCV_LIBRARIES}
)

add_executable(life-of-boids main.cpp)
target_link_libraries(life-of-boids PRIVATE ${COMMON_LIBS})
target_include_directories(life-of-boids PRIVATE ${OpenCV_INCLUDE_DIRS})

add_executable(chrono main_chrono.cpp)
target_link_libraries(chrono PRIVATE ${COMMON_LIBS})
target_include_directories(chrono PRIVATE ${OpenCV_INCLUDE_DIRS})
