#!/bin/sh

set -e
set -x

case "${os}" in
  linux32)
    cmake -DOPT:STRING=release -DTARGET:STRING=linux32 -DCMAKE_CXX_COMPILER=g++-5 -DCMAKE_C_COMPILER=gcc-5 .
    make clean
    make VERBOSE=1 zip || true
    g++-5 -m32  -std=c++14 -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -O2  -lSDL2 -lSDL2_image -lm CMakeFiles/spacepilot.dir/main.cc.o CMakeFiles/spacepilot.dir/Bullet.cc.o CMakeFiles/spacepilot.dir/Enemy.cc.o CMakeFiles/spacepilot.dir/Entity.cc.o CMakeFiles/spacepilot.dir/Game.cc.o CMakeFiles/spacepilot.dir/InputHandler.cc.o CMakeFiles/spacepilot.dir/Levels.cc.o CMakeFiles/spacepilot.dir/Menu.cc.o CMakeFiles/spacepilot.dir/Player.cc.o CMakeFiles/spacepilot.dir/Renderer.cc.o CMakeFiles/spacepilot.dir/Star.cc.o CMakeFiles/spacepilot.dir/Texture.cc.o  -o spacepilot -rdynamic
    ;;
  linux64)
    cmake -DOPT:STRING=release -DTARGET:STRING=linux64 -DCMAKE_CXX_COMPILER=g++-5 .
    make clean
    make VERBOSE=1 zip || true
    g++-5  -std=c++14 -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -O2  -lSDL2 -lSDL2_image -lm CMakeFiles/spacepilot.dir/main.cc.o CMakeFiles/spacepilot.dir/Bullet.cc.o CMakeFiles/spacepilot.dir/Enemy.cc.o CMakeFiles/spacepilot.dir/Entity.cc.o CMakeFiles/spacepilot.dir/Game.cc.o CMakeFiles/spacepilot.dir/InputHandler.cc.o CMakeFiles/spacepilot.dir/Levels.cc.o CMakeFiles/spacepilot.dir/Menu.cc.o CMakeFiles/spacepilot.dir/Player.cc.o CMakeFiles/spacepilot.dir/Renderer.cc.o CMakeFiles/spacepilot.dir/Star.cc.o CMakeFiles/spacepilot.dir/Texture.cc.o  -o spacepilot -rdynamic
    ;;
  win32)
    cmake -DOPT:STRING=release -DTARGET:STRING=win32 -DCMAKE_C_COMPILER=i686-w64-mingw32-gcc -DCMAKE_CXX_COMPILER=i686-w64-mingw32-g++-posix -DCMAKE_SYSTEM_NAME=Windows .
    make clean
    make VERBOSE=1 zip
    ;;
esac
