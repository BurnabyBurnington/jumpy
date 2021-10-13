add_executable(jumpy_game
    main.cpp
)

target_compile_features(jumpy_game PRIVATE cxx_std_17)

target_include_directories(jumpy_game PRIVATE private)

target_link_libraries(jumpy_game PRIVATE jumpy_engine::jumpy_engine)
target_link_libraries(jumpy_game PRIVATE Qt5::Widgets Qt5::OpenGL)
