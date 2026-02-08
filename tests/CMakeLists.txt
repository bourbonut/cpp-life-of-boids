include(CTest)
include(GoogleTest)

# Build a list of test binaries
add_executable(first_gtest first_gtest.cpp)
target_link_libraries(first_gtest PRIVATE gtest gtest_main)
target_include_directories(first_gtest PRIVATE ${GTest_INCLUDE_DIRS})
gtest_discover_tests(first_gtest)

add_executable(test_math test_math.cpp)
target_link_libraries(test_math PRIVATE myMath gtest gtest_main)
target_include_directories(test_math PRIVATE ${CMAKE_SOURCE_DIR}/src)
gtest_discover_tests(test_math)

add_executable(test_bird test_bird.cpp)
target_link_libraries(test_bird PRIVATE myBirds myLaws myMath gtest gtest_main flockGenerator)
target_include_directories(test_bird PRIVATE ${CMAKE_SOURCE_DIR}/src)
gtest_discover_tests(test_bird)

add_executable(test_graphics test_graphics.cpp)
target_link_libraries(test_graphics PRIVATE libGLX myBirds myLaws myMath gtest gtest_main)
target_include_directories(test_graphics PRIVATE ${CMAKE_SOURCE_DIR}/src)
gtest_discover_tests(test_graphics)

add_executable(test_law "test_law.cpp")
target_link_libraries(test_law PRIVATE myBirds myLaws myMath gtest gtest_main)
target_include_directories(test_law PRIVATE ${CMAKE_SOURCE_DIR}/src)
gtest_discover_tests(test_law)
