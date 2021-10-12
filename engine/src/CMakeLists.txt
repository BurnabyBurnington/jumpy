# 1. Define the base engine
add_library(jumpy_engine
    SHARED
        lib/window.cpp
)

target_include_directories(jumpy_engine
    PRIVATE
        include
)

# 2. Install the engine as a shared library
install(
    TARGETS jumpy_engine
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# 3. Export the engine so games can use it
include(cmake/export_all.cmake)
