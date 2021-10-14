# CMake generated Testfile for 
# Source directory: /data/tests
# Build directory: /data/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
include("/data/build/tests/first_gtest[1]_include.cmake")
include("/data/build/tests/test_math[1]_include.cmake")
include("/data/build/tests/test_bird[1]_include.cmake")
add_test(FirstTest "/data/build/tests/first_test")
set_tests_properties(FirstTest PROPERTIES  _BACKTRACE_TRIPLES "/data/tests/CMakeLists.txt;9;add_test;/data/tests/CMakeLists.txt;0;")
add_test(test_math "/data/build/tests/test_math")
set_tests_properties(test_math PROPERTIES  _BACKTRACE_TRIPLES "/data/tests/CMakeLists.txt;22;add_test;/data/tests/CMakeLists.txt;0;")
add_test(test_bird "/data/build/tests/test_bird")
set_tests_properties(test_bird PROPERTIES  _BACKTRACE_TRIPLES "/data/tests/CMakeLists.txt;28;add_test;/data/tests/CMakeLists.txt;0;")
