cmake_minimum_required(VERSION 3.3)
project(spacepilot)

set(TARGET "linux64" CACHE STRING "use linux64/linux32/win32")
set(OPT "debug" CACHE STRING "use debug/release")


set(CMAKE_CXX_FLAGS "-std=c++14 -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused")
set(SOURCE_FILES main.cc Bullet.cc Enemy.cc Entity.cc Game.cc InputHandler.cc Levels.cc Menu.cc Player.cc Renderer.cc Star.cc Texture.cc)
set(CMAKE_EXE_LINKER_FLAGS "-lSDL2 -lSDL2_image -lm")

IF (${OPT} STREQUAL "debug")
    MESSAGE(STATUS "setting for debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
ELSEIF (${OPT} STREQUAL "release")
    MESSAGE(STATUS "setting for release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
ENDIF ()

IF (${TARGET} STREQUAL "linux64")
    MESSAGE(STATUS "setting for linux64")
    add_executable(spacepilot ${SOURCE_FILES})
    add_custom_target(zip COMMAND ./pack.sh)
    add_dependencies(zip spacepilot)
ELSEIF (${TARGET} STREQUAL "linux32")
    MESSAGE(STATUS "setting for linux32")
    set(CMAKE_CXX_FLAGS "-m32 ${CMAKE_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "-m32 ${CMAKE_EXE_LINKER_FLAGS}")
    add_executable(spacepilot ${SOURCE_FILES})
    add_custom_target(zip COMMAND ./pack.sh)
    add_dependencies(zip spacepilot)
ELSEIF (${TARGET} STREQUAL "win32")
    MESSAGE(STATUS "setting for win32")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,subsystem,windows -ISDL2-2.0.3/i686-w64-mingw32/include/")
    set(CMAKE_EXE_LINKER_FLAGS "-mwindows -lmingw32 -lSDL2main ${CMAKE_EXE_LINKER_FLAGS} -LSDL2-2.0.3/i686-w64-mingw32/lib/ -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread")
    add_executable(spacepilot.exe ${SOURCE_FILES})
    add_custom_target(zip COMMAND ./pack.sh windows)
    add_dependencies(zip spacepilot.exe)
ENDIF ()

MESSAGE(STATUS "compiler flags: " ${CMAKE_CXX_FLAGS})
MESSAGE(STATUS "linker flags:   " ${CMAKE_EXE_LINKER_FLAGS})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")




