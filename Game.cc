#include "Game.hh"
#include "Player.hh"
#include "global.hh"
#include "Renderer.hh"
#include "InputHandler.hh"
#include <iostream>

Game* Game::instance;

Game* Game::createInstance(){
	Game::instance = new Game();
	return Game::instance;
}

Game* Game::getInstance(){
	return Game::instance;
}

Game::Game(){
}

void Game::addEntity(Entity *e){
	toAddList.push_back(e);
}

void Game::removeEntity(Entity *e){
	toDelList.push_back(e);
}

void Game::run(){
	
	Renderer renderer(HSIZE, VSIZE, "Ludum Dare 34");
	if(!renderer.isOk()){
		std::cout << "Ending program" << std::endl;
		return;
	}

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
		for(auto i = entityList.begin(); i != entityList.end(); ++i){
			(*i)->render();
		}

		entityList.insert(entityList.end(), toAddList.begin(), toAddList.end());
		toAddList.clear();

		for(auto d = toDelList.begin(); d != toDelList.end(); ++d){
			for(auto i = entityList.begin(); i != entityList.end(); i++){
				if(*i == *d){
					entityList.erase(i);
					break;
				}
			}
		}
		renderer.update();
	}


}

