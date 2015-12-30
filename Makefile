SOURCES := main.cc Renderer.cc Texture.cc InputHandler.cc Player.cc Bullet.cc Game.cc Enemy.cc Star.cc Entity.cc Menu.cc Levels.cc
HEADERS := $(wildcard *.hh)
OBJECTS := $(addprefix obj/,$(SOURCES:.cc=.o))

ifeq ($(target),win32)
	EXECUTABLE := spacepilot.exe
	CFLAGS := -c -std=c++14 -Wall -Wextra -pedantic -Wl,subsystem,windows -ISDL2-2.0.3/i686-w64-mingw32/include/
	LDFLAGS := -mwindows -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -LSDL2-2.0.3/i686-w64-mingw32/lib/ -static-libgcc -static-libstdc++ -lm -Wl,-Bstatic -lstdc++ -lpthread

else ifeq ($(target),linux32)
	EXECUTABLE := spacepilot
	CFLAGS := -c -m32 -std=c++14 -Wall -Wextra -pedantic
	LDFLAGS := -m32 -lSDL2 -lSDL2_image -lm
else
	EXECUTABLE := spacepilot
	CFLAGS := -c -std=c++14 -Wall -Wextra -pedantic
	LDFLAGS:= -lSDL2 -lSDL2_image -lm
endif

debug: CFLAGS+=-g
debug: all

profile: CFLAGS+=-pg
profile: LDFLAGS+=-pg
profile: debug

all: create_dir $(SOURCES) $(EXECUTABLE)

release: CFLAGS+=-O2
release: all

create_dir:
	mkdir -p obj

$(EXECUTABLE): $(OBJECTS) 
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

-include deps

$(OBJECTS): obj/%.o : %.cc $(HEADERS)
	$(CXX) $(CFLAGS) $< -o $@

clean:
	rm -rf obj 2>/dev/null || true
	rm -rf $(EXECUTABLE) 2>/dev/null || true

zip: all
	ln -s . SpacePilot
	rm SpacePilot.zip 2>/dev/null || true
ifeq ($(target),windows)
	zip SpacePilot.zip SpacePilot/spacepilot* SpacePilot/img/*.png SpacePilot/SDL2.dll SpacePilot/SDL2_image.dll SpacePilot/zlib1.dll SpacePilot/libpng16-16.dll SpacePilot/README SpacePilot/LICENSE
else
	zip SpacePilot.zip SpacePilot/spacepilot* SpacePilot/img/*.png SpacePilot/README SpacePilot/LICENSE
endif
