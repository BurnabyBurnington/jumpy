add_library(testing OBJECT test_main.cpp)

add_executable(test_simple test_simple.cpp $<TARGET_OBJECTS:testing>)
add_test(NAME test_simple COMMAND test_simple)
