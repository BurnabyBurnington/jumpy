## TODO
- Make the reflexivity methods of Vector{2,3}D and other classes call the OTHER method, instead of redefine the same information

- Rename test suite names to be more specific (e.g. "vector2DMultiplication" instead of "vectorMultiplication")
- Change unittesting to instead be assert-based (so we can have more
  than one test in a single executable)
- Check if methods can use symbols, like +=
- Make clock into a context block, because that's more fun

- Consider moving Clock into a separate namespace
- Figure out a way to only run one test at a time


## Local Build
```sh
export CC=/opt/rh/devtoolset-9/root/bin/gcc
export CXX=/opt/rh/devtoolset-9/root/bin/g++
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=$PWD/install
cmake --build . --target install
```

### To Run Tests
```sh
./tests/run_tests
```


SET CMAKE_PREFIX_PATH=C:\Qt_new\6.2.0\mingw81_64\lib\cmake
SET CMAKE_PREFIX_PATH=C:\Qt\5.9\winrt_x64_msvc2017\lib\cmake


set PATH=C:\Program Files (x86)\MSBuild\15.0\.Net\.NetNative\15.0.24211\x64\ilc\lib\MSCRT;%PATH%


TODO remove these old instructions


## Requires
- A C++17+ compiler


## To Build
### Environment
QT_INCLUDE_DIRECTORY - e.g. "C:\Qt_new\6.2.0\mingw81_64\include"
QT_LIBRARY_DIRECTORY - e.g. "C:\Qt_new\6.2.0\mingw81_64\lib"


### Build Commands
TODO remove one of these
cmake . -B "build64" && cmake --build build64 --config Release
```sh
cmake . -B "build64"
cmake --build build64 --config Release
.\build64\src\Release\jumpy_engine.exe
```

```sh
cmake -G "Visual Studio 16 2019" -A Win64 -S . -B "build64"
cmake --build build64 --config Release
.\build64\src\Release\jumpy_engine.exe
```
