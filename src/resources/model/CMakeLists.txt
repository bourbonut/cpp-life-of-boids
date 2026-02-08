file(GLOB SOURCES "*.cpp" "*.hpp" "../../lib/myMath/*.hpp" "../../lib/myMath/*.cpp")

add_library(myBirds "${SOURCES}")
target_link_libraries(myBirds PUBLIC tbb)
