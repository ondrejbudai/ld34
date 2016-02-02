#!/bin/sh

set -e
set -x

case "${os}" in
  linux32)
    cmake -DOPT:STRING=release -DTARGET:STRING=linux32 -DCMAKE_CXX_COMPILER=g++-5 -DCMAKE_C_COMPILER=gcc-5 .
    make clean
    make VERBOSE=1 zip
    ;;
  linux64)
    cmake -DOPT:STRING=release -DTARGET:STRING=linux64 -DCMAKE_CXX_COMPILER=g++-5 .
    make clean
    make VERBOSE=1 zip
    ;;
  win32)
    cmake -DOPT:STRING=release -DTARGET:STRING=win32 -DCMAKE_CXX_COMPILER=i686-w64-mingw32-g++-posix -DCMAKE_SYSTEM_NAME=Windows .
    make clean
    make VERBOSE=1 zip
    ;;
esac
