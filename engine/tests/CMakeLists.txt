add_executable(test_vector test_vector.cpp)
target_link_libraries(test_vector
    PRIVATE
        jumpy_engine
)
target_include_directories(test_vector
    PRIVATE
        ../src/include
)
add_test(NAME test_vector COMMAND test_vector)
