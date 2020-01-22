# MandelBulb
MandelBulb is a software

## Compiling
In order to compile the software, run the following command after cloning the repo:
```shell
cmake -B build && cmake --build build
```
Then you can launch it with `./build/MandelBulb`

## Dependencies
### Mandelbulb:
- [GLFW][1]
- [GLAD][2]
- [GLM][3]
- [STB][4]
- [JSON for Modern C++][5]
- [QT Creator][6]
### Tests
- [gtest][7]

[1]: https://github.com/glfw/glfw
[2]: https://github.com/Dav1dde/glad
[3]: https://github.com/g-truc/glm
[4]: https://github.com/nothings/stb
[5]: https://github.com/nlohmann/json
[6]: https://www.qt.io/download
[7]: https://github.com/google/googletest

## How to compile
After cloning the repo, run:
```shell
pushd <repoDir>
cmake -S . -B cmake-build-debug
pushd cmake-build-debug
cmake --build . --target MandelBulb
```
Execute `./MandelBulb` to run the program.