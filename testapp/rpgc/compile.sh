#!/bin/bash

# x32 build
g++ -m32 -o rpgc.bin ./src/rpgc.cpp

# x64 build
g++ -m64 -o rpgc64.bin ./src/rpgc.cpp
git add -A
