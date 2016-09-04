cmake_minimum_required(VERSION 3.5)
project(data_structure)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES

        src/main.cpp src/ds/trine.cpp src/ds/trine.h)
add_executable(data_structure ${SOURCE_FILES})

