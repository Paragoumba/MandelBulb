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
- [STB][3]
- [JSON for Modern C++][4]
### Tests
- [gtest][5]

[1]: https://github.com/glfw/glfw
[2]: https://github.com/Dav1dde/glad
[3]: https://github.com/nothings/stb
[4]: https://github.com/nlohmann/json
[5]: https://github.com/google/googletest