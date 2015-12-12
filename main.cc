#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <SDL2/SDL.h>

#include "Renderer.hh"
#include "Texture.hh"
#include "InputHandler.hh"
#include "Player.hh"
#include "global.hh"

int main(int argc, char* argv[]){
	(void) argc; (void) argv;
	using namespace std;

	std::vector<Entity *> entityList;
	
	Renderer renderer(HSIZE, VSIZE, "Ludum Dare 34");
	if(!renderer.isOk()){
		cout << "Ending program" << endl;
		return EXIT_FAILURE;
	}
	srand(time(NULL));

	InputHandler* input = InputHandler::getInstance();
	Player player(&renderer);
	entityList.push_back(&player);

	input->registerKey(SDLK_s, &player);
	input->registerKey(SDLK_l, &player);
	input->registerKey(SDLK_d, &player);

	bool running = true;
	unsigned long lastFrame = 0;
	while(running){
		if(lastFrame + 1000 / 60 > SDL_GetTicks()){
			SDL_Delay(1);
			continue;
		}
		lastFrame += 1000 / 60;
		running = input->update();
		renderer.clear();
		
		for(auto i = entityList.begin(); i != entityList.end(); ++i){
			(*i)->update();
		}

		player.render();
		renderer.update();
	}

	return 0;
}
