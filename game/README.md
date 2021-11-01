## TODO
- Do the final section for the game loop, later - https://gafferongames.com/post/fix_your_timestep/
 - "The final touch"

Check this out
https://github.com/bvdberg/ctest
https://github.com/Azure/ctest
https://stackoverflow.com/questions/733475/cmake-ctest-make-test-doesnt-build-tests
https://baoilleach.blogspot.com/2013/06/using-ctest-with-multiple-tests-in.html
https://stackoverflow.com/questions/60505013/ctest-and-multi-test-binaries
https://stackoverflow.com/questions/48995697/cmake-configuration-for-multiple-test-files
https://crascit.com/2016/10/18/test-fixtures-with-cmake-ctest/
https://stackoverflow.com/questions/3065220/ctest-with-multiple-commands


## Building & Running
### Requirements
1. Build the game engine if you haven't already. (See
   [README.md](../engine/README.md))

2. Install additional display-related dependencies

```sh
sudo yum install -y glew qt5 opengl
```

### Build
```sh
mkdir build
cd build
cmake ..
cmake --build .
```

TODO check if this works
```sh
cmake -S . -B build
cmake --build build
```


## Building And Running Tests
### Requirements
These requirements are only needed if you want to run the unittest suite

```sh
sudo yum install -y gtest
```

### Build And Run
TODO


## Additional Notes
Uses GLEW 2.2.0


https://raymii.org/s/tutorials/Cpp_project_setup_with_cmake_and_unit_tests.html
https://stackoverflow.com/questions/8507723/how-to-start-working-with-gtest-and-cmake
https://raymii.org/s/tutorials/Cpp_project_setup_with_cmake_and_unit_tests.html
https://google.github.io/googletest/quickstart-cmake.html
https://stackoverflow.com/questions/40077146/running-google-test-at-build-time-with-cmake-generated-system


Best success with this one
https://a4z.gitlab.io/blog/2018/05/17/Speed-up-your-test-cycles-with-CMake.html

Possibly? Seems legit
https://cmake.org/cmake/help/latest/command/enable_testing.html
https://stackoverflow.com/a/50476125

https://bastian.rieck.me/blog/posts/2017/simple_unit_tests/
https://riptutorial.com/cmake/example/14698/basic-test-suite

Maybe?
https://bastian.rieck.me/blog/posts/2017/simple_unit_tests/

Possible?
https://github.com/a4z/cmaketestblogexample1/blob/master/test1.cpp

What is this?
https://stackoverflow.com/questions/59093114/in-unit-testing-how-to-compare-two-objects-without-using-operator-which-may-m

https://stackoverflow.com/questions/50468620/what-does-enable-testing-do-in-cmake
