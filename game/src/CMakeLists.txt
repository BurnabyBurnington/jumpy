add_executable(jumpy_game
    main.cpp
    private/keyState.cpp
    private/window.cpp
)

target_compile_features(jumpy_game PRIVATE cxx_std_17)

# TODO: Add this back in, once I get Windows support
# if(MSVC)
#     target_compile_options(jumpy_game PRIVATE /W4 /WX)
# else()
#     target_compile_options(jumpy_game PRIVATE -Wall -Wextra -Wpedantic -Werror)
# endif()
#
target_compile_options(jumpy_game PRIVATE -Wall -Wextra -Wpedantic -Werror)

target_include_directories(jumpy_game PRIVATE private)

target_link_libraries(jumpy_game
    PRIVATE
        GLEW
        OpenGL
        Qt5::OpenGL
        Qt5::Widgets
        X11  # TODO: Check to make sure this works

        jumpy_engine::jumpy_engine
)
