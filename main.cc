#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <SDL2/SDL.h>

#include "Game.hh"

int main(int argc, char* argv[]){
	(void) argc; (void) argv;

	Game *g = Game::createInstance();


	g->run();

	return 0;
}
