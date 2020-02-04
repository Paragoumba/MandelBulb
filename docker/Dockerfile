FROM alpine:3.11.3

RUN apk add --no-cache git g++ cmake make glfw-dev glm-dev gtest-dev doxygen graphviz

WORKDIR /usr/include
COPY /stb stb
COPY /glad glad
COPY /KHR KHR
COPY /GL GL

WORKDIR /
