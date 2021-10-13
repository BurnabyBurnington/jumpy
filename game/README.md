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
