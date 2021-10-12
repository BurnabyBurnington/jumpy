cmake_minimum_required(VERSION 3.16)
project(jumpy_game LANGUAGES CXX)

# If in a distributed build, this find_package would instead get from CMAKE_PREFIX_PATH
find_package(jumpy_engine HINT ${CMAKE_CURRENT_SOURCE_DIR}../engine/)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_subdirectory(src)
