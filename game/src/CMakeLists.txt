add_executable(jumpy_game
    PRIVATE
        main.cpp
)

target_compile_features(jumpy_game PRIVATE cxx_std_17)
target_link_libraries(jumpy_game PRIVATE Qt5::Widgets)

install(
    DIRECTORY
        include
    DESTINATION
        include
)
