cmake_minimum_required(VERSION 3.16)
project(jumpy_engine LANGUAGES CXX)

add_subdirectory(src)

# Reference: https://cmake.org/cmake/help/latest/command/enable_testing.html
# Reference: https://stackoverflow.com/a/50476125
#
include(CTest)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
