cmake_minimum_required(VERSION 3.16)
project(jumpy LANGUAGES CXX)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_subdirectory(src)
