cmake_minimum_required(VERSION 3.6)
project(trine-library)
add_definitions(-std=c++14)
include_directories(trine-library/src)

add_subdirectory(trine-library/src)
add_subdirectory(trine-library/test)
add_executable(trine-run main.cpp)
target_link_libraries(trine-run trine-library)

