cmake_minimum_required(VERSION 3.0)
project(basics_cpp)
set (CMAKE_CXX_STANDARD 11)
# locate GTest
find_package(GTest REQUIRED)
include_directories($(GTEST_INCLUDE_DIRS))
include_directories(./includes)
include_directories(./src)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(executeTests src/tester_main.cpp src/merge_sort.cpp src/sorting_tests.cpp src/quicksort.cpp)
target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)