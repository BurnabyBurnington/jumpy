# 1. Define the base engine
add_library(jumpy_engine
    SHARED
        lib/window.cpp
)

target_include_directories(jumpy_engine
    PRIVATE
        include
)

# 2. Export / Install everything
include(cmake/export_all.cmake)

install(
    DIRECTORY
        include
    DESTINATION
        include
)
