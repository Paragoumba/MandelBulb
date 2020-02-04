#!/bin/bash
if [[ ! -d "/usr/include/gtest" ]]; then
	echo "Required dependency gtest isn't installed!"
	exit 1
fi

cp -r /usr/include/gtest .

if [[ ! -d "/usr/local/include/stb" ]]; then
	echo "Required dependency stb isn't installed!"
	exit 1
fi

cp -r /usr/local/include/stb .

if [[ ! -d "/usr/include/glm" ]]; then
	echo "Required dependency glm isn't installed!"
	exit 1
fi

cp -r /usr/include/glm .

if [[ ! -d "/usr/local/include/glad" ]]; then
	echo "Required dependency glad isn't installed!"
	exit 1	
fi

cp -r /usr/local/include/glad .

if [[ ! -d "/usr/local/include/KHR" ]]; then
	echo "Required dependency KHR isn't installed"
	exit 1
fi

cp -r /usr/local/include/KHR .

if [[ ! -d "/usr/include/GLFW" ]]; then
	echo "Required dependency GLFW isn't installed!"
	exit 1
fi

cp -r /usr/include/GLFW .

if [[ ! -d "/usr/include/GL" ]]; then
	echo "Required dependency GL isn't installed!"
	exit 1
fi

cp -r /usr/include/GL .

echo -e "-- Building image\n"
docker build -t paragoumba/cpp-ci-cd-opengl . || { echo "Is Docker service running?" && exit 1; }
echo -e "\nPush Image? O/n"

read -r y

if [[ "$y" = "O" || "$y" = "o" || "$y" = "" ]]; then
	echo -e "\n-- Pushing image\n"
	docker push paragoumba/cpp-ci-cd-opengl
fi
