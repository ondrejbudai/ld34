#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <SDL2/SDL.h>

#include "Renderer.hh"
#include "GameState.hh"
#include "Menu.hh"
#include "global.hh"

int main(int argc, char* argv[]){
	(void) argc; (void) argv;
	
	Renderer* renderer = new Renderer(WINDOW_W, WINDOW_H, "Ludum Dare 34");
	if(!renderer->isOk()){
		std::cout << "Ending program" << std::endl;
		return 1;
	}

	srand(time(NULL));

	GameState* gs = new Menu(renderer);

	while(gs != NULL){
		gs = gs->run();
	}

	delete(renderer);

	return 0;
}
