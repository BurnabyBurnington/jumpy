# 1. Define the base engine
add_library(jumpy_engine
    SHARED
        lib/clock.cpp
        lib/matrix2D.cpp
        lib/vector2D.cpp
)

target_include_directories(jumpy_engine
    PRIVATE
        include
)

# 2. Install the engine as a shared library
include(GNUInstallDirs)  # Needed for CMAKE_INSTALL_*DIR variables
install(
    TARGETS jumpy_engine
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
install(
    DIRECTORY
        include
    DESTINATION
        .
)

# 3. Export the engine so games can use it
include(cmake/export_all.cmake)
