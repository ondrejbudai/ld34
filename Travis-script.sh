#!/bin/sh

set -e
set -x

case "${os}" in
  linux32)
    cmake -DOPT:STRING=release -DTARGET:STRING=linux32 .
    make clean
    make zip
    ;;
  linux64)
    cmake -DOPT:STRING=release -DTARGET:STRING=linux64 .
    make clean
    make zip
    ;;
  win32)
    make clean
    make zip
    ;;
esac
