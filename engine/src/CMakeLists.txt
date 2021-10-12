add_executable(jumpy_engine
	main.cpp
)

target_compile_features(jumpy_engine PRIVATE cxx_std_17)
target_link_libraries(jumpy_engine PRIVATE Qt5::Widgets)

# TODO : Fix this later
install(
    TARGETS jumpy_engine
    DESTINATION .
)
