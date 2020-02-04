#!/bin/bash
function search(){

  whereis -b -B /usr/include /usr/local/include/ -f "$1" | cut -d' ' -f2

}

for value in stb glad KHR GL; do
  dir=$(search $value)
  echo "$dir"
  if [[ ! -d "$dir" ]]; then
	  echo "Required dependency $value isn't installed!"
	  exit 1
  fi

  cp -r "$dir" .
done

echo -e "-- Building image\n"
docker build -t paragoumba/cpp-ci-cd-opengl . || { echo "Is Docker service running?" && exit 1; }
echo -e "\nPush Image? O/n"

read -r y

if [[ "$y" = "O" || "$y" = "o" || "$y" = "" ]]; then
	echo -e "\n-- Pushing image\n"
	docker push paragoumba/cpp-ci-cd-opengl
fi
