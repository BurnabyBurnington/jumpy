SET CMAKE_PREFIX_PATH=C:\Qt_new\6.2.0\mingw81_64\lib\cmake




## Requires
- A C++17+ compiler


## To Build
### Environment
QT_INCLUDE_DIRECTORY - e.g. "C:\Qt_new\6.2.0\mingw81_64\include"
QT_LIBRARY_DIRECTORY - e.g. "C:\Qt_new\6.2.0\mingw81_64\lib"


### Build Commands
TODO remove one of these
```sh
cmake . -B "build64"
cmake --build build64 --config Release
```

```sh
cmake -G "Visual Studio 16 2019" -A Win64 -S . -B "build64"
cmake --build build64 --config Release
```
