# add_executable(test_vector test_vector.cpp)
# target_link_libraries(test_vector
#     PRIVATE
#         jumpy_engine
# )
# target_include_directories(test_vector
#     PRIVATE
#         ../src/include
# )
# add_test(NAME test_vector COMMAND test_vector)

add_executable(run_tests
    test_main.cpp
    testVector2D/test_addition.cpp
)
target_compile_features(run_tests PRIVATE cxx_std_17)
target_link_libraries(run_tests
    PRIVATE
        jumpy_engine
)
target_include_directories(run_tests
    PRIVATE
        ../src/include
        common
)
