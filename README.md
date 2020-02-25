# MandelBulb
MandelBulb is a software that renders fractals in 3D by raymarching
them.

![Gitlab pipeline status](https://img.shields.io/gitlab/pipeline/Paragoumba/mandelbulb)

## Dependencies
### MandelBulb:
- [GLFW][1]
- [GLAD][2]
- [GLM][3]
- [STB][4]
- [JSON for Modern C++][5]
### Tests
- [gtest][6]

[1]: https://github.com/glfw/glfw
[2]: https://github.com/Dav1dde/glad
[3]: https://github.com/g-truc/glm
[4]: https://github.com/nothings/stb
[5]: https://github.com/nlohmann/json
[6]: https://github.com/google/googletest

## How to compile
After cloning the repo, run:
```shell
pushd <repoDir>
cmake -S . -B cmake-build-debug
pushd cmake-build-debug
cmake --build . --target MandelBulb
pushd ../src/cmake-build-debug
```
Execute `./MandelBulb` to run the program.