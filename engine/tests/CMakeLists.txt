add_executable(run_tests
    testVector2D/testAddition.cpp
    testVector2D/testMisc.cpp
    testVector2D/testMultiplication.cpp
    testMain.cpp
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
