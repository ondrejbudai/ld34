#!/bin/sh

set -e
set -x

case "${os}" in
  linux32)
    cmake -DOPT:STRING=release -DTARGET:STRING=linux32 -DCMAKE_CXX_COMPILER=g++-5 -DCMAKE_C_COMPILER=gcc-5 .
    make clean
    make VERBOSE=1 zip || true
    ;;
  linux64)
    cmake -DOPT:STRING=release -DTARGET:STRING=linux64 -DCMAKE_CXX_COMPILER=g++-5 .
    make clean
    make VERBOSE=1 zip || true
    ;;
  win32)
    cmake -DCMAKE_TOOLCHAIN_FILE=mingw-toolchain.cmake -DOPT:STRING=release -DTARGET:STRING=win32 .
    make clean
    make VERBOSE=1 zip
    ;;
esac
