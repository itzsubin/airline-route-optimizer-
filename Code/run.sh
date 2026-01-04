#!/bin/bash
echo "Let's build our airline program!"

mkdir -p build
cd build 

echo "Compiling..."
clang++ -std=c++17 -g -o routeSearch \
    ../src/main.cpp \
    ../src/Graph.cpp \
    ../src/RouteFinder.cpp \
    ../src/FileParser.cpp \
    ../src/utilis.cpp

if [ $? -eq 0 ]; then
    echo "Yay! running..!"
    echo "Now serving your program:"
    ./routeSearch "$@"
else
    echo "Oops! running fail!"
    exit 1
fi