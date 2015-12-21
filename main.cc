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
	
	Renderer* renderer = new Renderer(WINDOW_W, WINDOW_H, "Space Pilot");
	if(!renderer->isOk()){
		std::cout << "Ending program" << std::endl;
		return 1;
	}

	renderer->setOffset(0, 50);

	srand(time(NULL));

	GameState* gs = new Menu(renderer);

	unsigned lastFrame = SDL_GetTicks();
	while(gs != NULL){


		if(lastFrame + 1000 > SDL_GetTicks() * 60){
			SDL_Delay(1);
			continue;
		}

		lastFrame += 1000;
		GameState* tmp;
		tmp = gs->update();
		renderer->clear();
		gs->render();
		renderer->update();

		if(gs != tmp)
			delete gs;

		gs = tmp;
	}

	delete renderer;

	return 0;
}
