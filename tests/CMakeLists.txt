include(CTest)

find_package(GTest REQUIRED)
include(GoogleTest)

# Build a list of test binaries
add_executable(first_test first_test.cpp)
target_link_libraries(first_test PRIVATE libGLX)
add_test(NAME FirstTest
        COMMAND first_test # with args
        )

add_executable(first_gtest first_gtest.cpp)
target_link_libraries(first_gtest PRIVATE GTest::gtest GTest::gtest_main)
target_include_directories(first_gtest PRIVATE ${GTest_INCLUDE_DIRS})
gtest_discover_tests(first_gtest) # helps to split one ctest executable into multiple google tests


add_executable(test_math test_math.cpp)
target_link_libraries(test_math myMath GTest::GTest)
target_include_directories(test_math PUBLIC ${CMAKE_SOURCE_DIR}/src)
add_test(NAME test_math COMMAND test_math)
gtest_discover_tests(test_math) # helps to split one ctest executable into multiple google tests

add_executable(test_bird test_bird.cpp)
target_link_libraries(test_bird birdsLib myMath GTest::GTest)
target_include_directories(test_bird PUBLIC ${CMAKE_SOURCE_DIR}/src)
add_test(NAME test_bird COMMAND test_bird)
gtest_discover_tests(test_bird) 