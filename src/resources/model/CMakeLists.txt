file(GLOB SOURCES "*.cpp" "*.hpp" "../../lib/myMath/*.hpp" "../../lib/myMath/*.cpp")

add_library(myBirds "${SOURCES}" )
