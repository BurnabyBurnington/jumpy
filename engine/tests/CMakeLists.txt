add_executable(test_simple test_simple.cpp)
target_link_libraries(test_simple
    PRIVATE
        jumpy_engine
)
target_include_directories(test_simple
    PRIVATE
        ../src/include
)
add_test(NAME test_vector COMMAND test_vector)
