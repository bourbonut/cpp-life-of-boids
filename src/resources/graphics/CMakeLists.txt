add_library(libGLX "glx.cpp" "glx.hpp" "GraphicalManager.hpp" "GraphicalManager.cpp" "graphics.hpp" "graphics.cpp" "oglTypes.hpp")
target_link_libraries(libGLX PUBLIC 
  glfw 
  glad 
  opencv_core
  opencv_imgcodecs
  myControllers
)
target_include_directories(libGLX PRIVATE ${OpenCV_INCLUDE_DIRS})
