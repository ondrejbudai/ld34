#!/bin/sh

set -ex

case "$os" in
  linux32)
    # Prepare an i386 chroot. This is required as we otherwise can't install
    # our dependencies to be able to compile a 32bit binary. Ubuntu...
    chroot="$PWD"/buildroot.i386
    mkdir -p "$chroot$PWD"
    sudo apt-get install -y debootstrap
    sudo i386 debootstrap --arch=i386 precise "$chroot"
    sudo mount --rbind "$PWD" "$chroot$PWD"
    sudo i386 chroot "$chroot" apt-get install -qq python-software-properties
    sudo i386 chroot "$chroot" add-apt-repository -y ppa:zoogie/sdl2-snapshots
    sudo i386 chroot "$chroot" add-apt-repository -y ppa:ubuntu-toolchain-r/test
    sudo i386 chroot "$chroot" apt-get update -qq
    sudo i386 chroot "$chroot" apt-get install -qq libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev g++-4.8 build-essential

    ;;
  linux64)
    sudo add-apt-repository -y ppa:zoogie/sdl2-snapshots
    sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
    sudo apt-get update -qq
    sudo apt-get install -qq libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev g++-4.8
    ;;
  win32)
    sudo sed -i -e "s/precise/vivid/g" /etc/apt/sources.list
    sudo apt-get update -qq
    sudo apt-get install -qq mingw-w64
    wget https://www.libsdl.org/release/SDL2-devel-2.0.3-mingw.tar.gz
    wget https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.0-mingw.tar.gz
    wget https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-devel-2.0.12-mingw.tar.gz
    tar axf SDL2-devel-2.0.3-mingw.tar.gz
    tar axf SDL2_image-devel-2.0.0-mingw.tar.gz
    tar axf SDL2_ttf-devel-2.0.12-mingw.tar.gz
    cp -rf SDL2_ttf-2.0.12/i686-w64-mingw32/* SDL2-2.0.3/i686-w64-mingw32/
    cp -rf SDL2_image-2.0.0/i686-w64-mingw32/* SDL2-2.0.3/i686-w64-mingw32/
    ;;
esac
