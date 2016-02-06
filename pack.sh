#!/bin/sh

ln -s . SpacePilot 2>/dev/null || true
rm SpacePilot.zip 2>/dev/null || true
if [ $# -ge 1 ] && [ "$1" ==  "windows" ]; then
	zip SpacePilot.zip SpacePilot/spacepilot.exe SpacePilot/img/*.png SpacePilot/SDL2.dll SpacePilot/SDL2_image.dll SpacePilot/zlib1.dll SpacePilot/libpng16-16.dll SpacePilot/README SpacePilot/LICENSE
else
	zip SpacePilot.zip SpacePilot/spacepilot SpacePilot/img/*.png SpacePilot/README SpacePilot/LICENSE
fi
