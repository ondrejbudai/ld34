SOURCES=main.cpp
OBJECTS=$(addprefix obj/,$(SOURCES:.cpp=.o))
EXECUTABLE=ld34

ifeq ($(target),windows)
	CFLAGS=-c -std=c++11 -Wall -pedantic -g -Wl,subsystem,windows -ISDL2-2.0.3/i686-w64-mingw32/include/
	LDFLAGS= -mwindows -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -LSDL2-2.0.3/i686-w64-mingw32/lib/ -static-libgcc -static-libstdc++

else
	CFLAGS=-c -std=c++11 -Wall -pedantic -g
	LDFLAGS= -lSDL2 -lSDL2_image -lSDL2_ttf
endif

all: create_dir $(SOURCES) $(EXECUTABLE)

create_dir:
	mkdir -p obj/cards
$(EXECUTABLE): $(OBJECTS) 
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

#.cpp.o:
$(OBJECTS): obj/%.o : %.cpp
	$(CXX) $(CFLAGS) $< -o $@

clean:
	rm -rf obj

# falešné cíle
.PHONY:
