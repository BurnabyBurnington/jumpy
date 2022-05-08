# 1. Define the base engine
add_library(jumpy_engine
    SHARED
        lib/clock.cpp
        lib/matrix2D.cpp
        lib/matrix3D.cpp
        lib/radian.cpp
        lib/vector2D.cpp
        lib/vector3D.cpp
)

# TODO: Add this back in, once I get Windows support
# if(MSVC)
#     target_compile_options(jumpy_engine PRIVATE /W4 /WX)
# else()
#     target_compile_options(jumpy_engine PRIVATE -Wall -Wextra -Wpedantic -Werror)
# endif()
#
target_compile_features(jumpy_engine PRIVATE cxx_std_17)
target_compile_options(jumpy_engine PRIVATE -Wall -Wextra -Wpedantic -Werror)

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
    FILES_MATCHING
        PATTERN
            "*.h"
        PATTERN
            ".ccls-cache" EXCLUDE  # Prevent IDE-related files from being copied
)

# 3. Export the engine so games can use it
include(cmake/export_all.cmake)
