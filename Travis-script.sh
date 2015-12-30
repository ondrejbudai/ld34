#!/bin/sh

set -e
set -x

case "${os}" in
  linux32)
    make clean
    make -j2 CXX="g++-5" target="linux32" release
    make -j2 CXX="g++-5" zip
    ;;
  linux64)
    make clean
    make -j2 CXX="g++-5" target="linux64" release
    make -j2 CXX="g++-5" zip
    ;;
  win32)
    make clean
    make -j2 CXX="i686-w64-mingw32-g++-posix" target="windows" release
    make -j2 CXX="i686-w64-mingw32-g++-posix" zip
    ;;
esac
