cmake_minimum_required(VERSION 3.16)
project(jumpy_game LANGUAGES CXX)

find_library(GLEW GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Qt5 COMPONENTS Widgets OpenGL REQUIRED)

# Reference: https://doc.qt.io/qt-5/cmake-get-started.html
#
# Note: Needed in order to MOC for signals and slots
# Reference: https://doc.qt.io/qt-5/moc.html
#
set(CMAKE_AUTOMOC ON)

# In a distributed build, this find_package would instead get from
# CMAKE_PREFIX_PATH But since the engine is in the same repository, we might as
# well cheat a bit :)
#
# If the engine is in another location, use CMAKE_PREFIX_PATH to point to that
# directory, instead.
#
find_package(JumpyEngine
    HINTS ${CMAKE_CURRENT_SOURCE_DIR}/../engine/build/install/lib/cmake/jumpy_engine REQUIRED
)

add_subdirectory(src)

# Reference: https://cmake.org/cmake/help/latest/command/enable_testing.html
# Reference: https://stackoverflow.com/a/50476125
#
include(CTest)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
