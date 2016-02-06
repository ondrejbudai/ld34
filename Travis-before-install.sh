#!/bin/sh

set -ex

case "$os" in
  linux32)
    sudo dpkg --add-architecture i386
    sudo add-apt-repository -y ppa:zoogie/sdl2-snapshots
    sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
    sudo apt-get update -y
    sudo apt-get remove -y cpp gcc g++
    sudo apt-get install -y libsdl2-dev:i386 libsdl2-image-dev:i386 g++-5:i386 gcc-5:i386 binutils:i386
    sudo apt-get install -f -y

    ;;
  linux64)
    sudo add-apt-repository -y ppa:zoogie/sdl2-snapshots
    sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
    sudo apt-get update -qq
    sudo apt-get install -qq libsdl2-dev libsdl2-image-dev g++-5
    ;;
  win32)
    sudo sed -i -e "s/trusty/xenial/g" /etc/apt/sources.list
    sudo apt-get remove -qq fontconfig fontconfig-config
    sudo apt-get update -qq
    echo "N" | sudo apt-get install -qq --only-upgrade dpkg
    sudo apt-get install -qq mingw-w64
    wget https://www.libsdl.org/release/SDL2-devel-2.0.3-mingw.tar.gz
    wget https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.0-mingw.tar.gz
    wget http://libsdl.org/release/SDL2-2.0.3-win32-x86.zip
    wget http://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.0-win32-x86.zip
    tar axf SDL2-devel-2.0.3-mingw.tar.gz
    tar axf SDL2_image-devel-2.0.0-mingw.tar.gz
    unzip -o SDL2-2.0.3-win32-x86.zip
    unzip -o SDL2_image-2.0.0-win32-x86.zip
    cp -rf SDL2_image-2.0.0/i686-w64-mingw32/* SDL2-2.0.3/i686-w64-mingw32/
    ;;
esac
