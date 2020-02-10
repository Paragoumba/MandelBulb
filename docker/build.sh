#!/bin/bash
OPTIONS=b::pr
LONGOPTS=build::,push,run,help

set -o errexit -o pipefail -o noclobber -o nounset

function search(){

  whereis -b -B /usr/include /usr/local/include/ -f "$1" | cut -d' ' -f2

}

! PARSED=$(getopt --options=$OPTIONS --longoptions=$LONGOPTS --name "$0" -- "$@")
[[ ${PIPESTATUS[0]} -ne 0 ]] && exit 2
eval set -- "$PARSED"

build=n run=n push=n
image=paragoumba/cpp-ci-cd-opengl
version=latest

while true; do
  case "$1" in
    --help)
      echo -e "Available flags:"
      echo -e "\t-b, --build\tOnly build the image."
      echo -e "\t-r, --run\tRun the image in a container after building it."
      echo -e "\t-p, --push\tOnly push the image. You'll be prompted before pushing."
      echo -e "\t--help\t\tDisplay the help."
      exit 0
      ;;
    -b|--build)
      build=y
      [[ ! "$2" = "" ]] && version="$2"
      shift 2
      ;;
    -p|--push)
      push=y
      shift
      ;;
    -r|--run)
      run=y
      shift
      ;;
    --)
      [[ "$build" = "n" && "$run" = "n" && "$push" = "n" ]] && build=y
      shift
      break
      ;;
    *)
      echo "Error \"$1\""
      exit 3
      ;;
  esac
done

if [[ "$build" = "y" ]]; then
  libs="stb glad KHR GL"

  for value in $libs; do
    dir=$(search "$value")
    if [[ ! -d "$dir" ]]; then
      echo "Required dependency $value isn't installed!"
      exit 1
    fi

    cp -r "$dir" .
  done

  echo -e "-- Building image $image:$version"

  if [[ $(systemctl is-active docker) = "inactive" ]]; then
      echo "Docker service isn't running."
      echo "Starting Docker service. You will be prompted for the root password."
      systemctl start docker
  fi

  docker build -t $image:"$version" .

  echo -e "-- Removing temp files"
  for value in $libs; do
    rm -r "$value"
  done

  echo "Done"
fi

if [[ "$push" = "y" ]]; then
  echo -e "Push Image? O/n"
  read -r y

  if [[ "$y" = "O" || "$y" = "o" || "$y" = "" ]]; then
    echo -e "-- Pushing image"
    docker push $image:"$version"
  fi
fi

if [[ "$run" = "y" ]]; then
  echo -e "-- Running image"
  docker run -it $image:"$version"
fi
