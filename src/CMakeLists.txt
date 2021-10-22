FIND_PACKAGE(glfw3 3.3 REQUIRED) # REQUIRED means : "fatal if not found"
FIND_PACKAGE(glad REQUIRED)
FIND_PACKAGE(OpenCV REQUIRED)

find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
  target_compile_options(my_app PUBLIC "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
  target_link_libraries(my_app "${CMAKE_THREAD_LIBS_INIT}")
endif()
#add_library(libGLX "resources/graphics/glx.cpp" "resources/graphics/glx.hpp" "resources/graphics/GraphicalManager.hpp" "resources/graphics/GraphicalManager.cpp" "resources/graphics/graphics.hpp" "resources/graphics/graphics.cpp" "resources/graphics/oglTypes.hpp")
#target_link_libraries(libGLX PUBLIC glfw::glfw glad::glad opencv::opencv)

add_subdirectory("lib/myLaws")
add_subdirectory("lib/myMath")
add_subdirectory("resources/graphics")
add_subdirectory("resources/model")
add_subdirectory("resources/controller")

add_executable(mathPart math_main.cpp)
target_link_libraries(mathPart PUBLIC myMath)


add_subdirectory("resources/graphics/shaders")

add_executable(graphicsTest graphics_main.cpp)
target_link_libraries(graphicsTest PUBLIC libGLX myMath shaders)

add_executable(life-of-boids main.cpp)
target_link_libraries(life-of-boids PUBLIC libGLX myMath shaders myBirds myLaws opencv::opencv flockGenerator)

#add_executable(main_opencv main_opencv.cpp)
#target_link_libraries(main_opencv PUBLIC opencv::opencv)
