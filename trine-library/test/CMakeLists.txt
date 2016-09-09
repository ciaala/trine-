

cmake_minimum_required(VERSION 3.6)
project(trine-test)
option(trine_build_tests "Build all of trine's unit tests." ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
find_package(GTest REQUIRED)

include(CTest)
#include_directories("/usr/local/include")
#link_directories("/usr/local/lib")
set(TEST_FILES
        ds/TrineTest.cpp)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(trine-test ${TEST_FILES})
target_link_libraries(trine-test trine-library ${GTEST_BOTH_LIBRARIES})
#GTEST_ADD_TESTS(trine-test)
add_test(AllTests trine-test)