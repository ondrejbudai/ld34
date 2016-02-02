cmake_minimum_required(VERSION 3.3)
project(spacepilot)

SET(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -pedantic -g -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused")
SET(CMAKE_EXE_LINKER_FLAGS "-lSDL2 -lSDL2_image -lm -g")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

set(SOURCE_FILES main.cc Bullet.cc Enemy.cc Entity.cc Game.cc InputHandler.cc Levels.cc Menu.cc Player.cc Renderer.cc Star.cc Texture.cc)
add_executable(spacepilot ${SOURCE_FILES})
