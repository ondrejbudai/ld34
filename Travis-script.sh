#!/bin/sh

set -e
set -x

case "${os}" in
  linux32)
    make target="linux32" clean
    make -j2 CXX="g++-5" target="linux32" release
    make -j2 CXX="g++-5" target="linux32" zip
    ;;
  linux64)
    make target="linux64" clean
    make -j2 CXX="g++-5" target="linux64" release
    make -j2 CXX="g++-5" target="linux64" zip
    ;;
  win32)
    make target="win32" clean
    make -j2 CXX="i686-w64-mingw32-g++-posix" target="win32" release
    make -j2 CXX="i686-w64-mingw32-g++-posix" target="win32" zip
    ;;
esac
