add_executable(jumpy_game
    main.cpp
    private/window.cpp
)

target_compile_features(jumpy_game PRIVATE cxx_std_17)

target_include_directories(jumpy_game PRIVATE private)

target_link_libraries(jumpy_game
    PRIVATE
        GLEW
        OpenGL
        Qt5::OpenGL
        Qt5::Widgets

        jumpy_engine::jumpy_engine
)
