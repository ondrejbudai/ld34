SOURCES := main.cc Renderer.cc Texture.cc InputHandler.cc Player.cc Bullet.cc Game.cc Enemy.cc Star.cc Entity.cc Menu.cc Levels.cc
HEADERS := $(wildcard *.hh)
OBJECTS := $(addprefix obj/,$(SOURCES:.cc=.o))
EXECUTABLE := ld34

ifeq ($(target),windows)
	CFLAGS=-c -std=c++11 -Wall -Wextra -pedantic -g -Wl,subsystem,windows -ISDL2-2.0.3/i686-w64-mingw32/include/
	LDFLAGS= -mwindows -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -LSDL2-2.0.3/i686-w64-mingw32/lib/ -static-libgcc -static-libstdc++ -lm

else
	CFLAGS=-c -std=c++11 -Wall -Wextra -pedantic -g
	LDFLAGS= -lSDL2 -lSDL2_image -lSDL2_ttf -lm
endif

all: create_dir $(SOURCES) $(EXECUTABLE)

create_dir:
	mkdir -p obj

$(EXECUTABLE): $(OBJECTS) 
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

-include deps

$(OBJECTS): obj/%.o : %.cc $(HEADERS)
	$(CXX) $(CFLAGS) $< -o $@

clean:
	rm -rf obj
	rm -rf $(EXECUTABLE)


# falešné cíle
.PHONY:
