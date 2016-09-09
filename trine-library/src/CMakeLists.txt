cmake_minimum_required(VERSION 3.6)
project(trine-library)
option(trine_build_tests "Build all of trine's unit tests." ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")



#include_directories("/usr/local/include")
#link_directories("/usr/local/lib")
set(LIBRARY_SOURCE_FILES
        trine/trine.cpp
        trine/trine.h
        )
add_library(trine-library ${LIBRARY_SOURCE_FILES})