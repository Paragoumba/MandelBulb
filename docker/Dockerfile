FROM archlinux:latest

RUN pacman -Sy --noconfirm git cmake make gcc glfw-x11 glm gtest doxygen graphviz

WORKDIR /usr/include
COPY /stb stb
COPY /glad glad
COPY /KHR KHR
COPY /GL GL

WORKDIR /
