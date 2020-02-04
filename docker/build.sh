#!/bin/bash
function search(){

  whereis -b -B /usr/include /usr/local/include/ -f "$1" | cut -d' ' -f2

}

libs="stb glad KHR GL"

for value in $libs; do
  dir=$(search "$value")
  if [[ ! -d "$dir" ]]; then
	  echo "Required dependency $value isn't installed!"
	  exit 1
  fi

  cp -r "$dir" .
done

echo -e "-- Building image\n"
docker build -t paragoumba/cpp-ci-cd-opengl . || { echo "Is Docker service running?" && exit 1; }

echo -e "-- Removing temp files"
for value in $libs; do
  rm -r "$value"
done

echo "Done"
echo -e "Push Image? O/n"

read -r y

if [[ "$y" = "O" || "$y" = "o" || "$y" = "" ]]; then
	echo -e "-- Pushing image\n"
	docker push paragoumba/cpp-ci-cd-opengl
fi
