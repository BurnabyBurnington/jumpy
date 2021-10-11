add_library(jumpy_engine
    SHARED
        main.cpp
)
target_include_directories(jumpy_engine PRIVATE $ENV{QT_INCLUDE_DIRECTORY})
target_link_libraries(jumpy_engine PRIVATE $ENV{QT_LIBRARY_DIRECTORY})

install(
    TARGETS jumpy_engine
    DESTINATION .
)
