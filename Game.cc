#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Game.hh"
#include "Player.hh"
#include "global.hh"
#include "Renderer.hh"
#include "InputHandler.hh"
#include "Enemy.hh"
#include "Levels.hh"
#include "Star.hh"

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

Entity* Game::getColliding(Entity *e, int x, int y){
	for(auto i = entityList.begin(); i != entityList.end(); ++i){
		if(*i == e) continue;
		if((*i)->colliding(x, y))
			return *i;
	}
	return nullptr;
}

void Game::updateLevel(unsigned ticks){
	static Level* current = levels;
	while(current->start == ticks){
		addEntity(new Enemy(renderer, GAME_W + current->x, GAME_H / 2 + current->y, current->vx, current->vy));
		current++;
	}
}

void Game::run(){
	
	renderer = new Renderer(WINDOW_W, WINDOW_H, "Ludum Dare 34");
	if(!renderer->isOk()){
		std::cout << "Ending program" << std::endl;
		return;
	}

	srand(time(NULL));

	InputHandler* input = new InputHandler();
	player = new Player(renderer);
	addEntity(player);

	input->registerKey(SDLK_UP, player);
	input->registerKey(SDLK_DOWN, player);
	input->registerKey(SDLK_w, player);	

	bool running = true;
	unsigned long lastFrame = 0;
	unsigned ticks = 0;
	while(running){
		if(lastFrame + 1000 / 60 > SDL_GetTicks()){
			SDL_Delay(1);
			continue;
		}
		lastFrame += 1000 / 60;
		running = input->update();
		renderer->clear();

		
		for(auto i = entityList.begin(); i != entityList.end(); ++i){
			(*i)->update();
		}

		if(rand() % 15 == 0){
			addEntity(new Star(renderer, GAME_W - 1, rand() % GAME_H, (rand() % 255 / 255.0f) * 0.75f + 0.25f, rand() % 191));
		}

		updateLevel(ticks);

		entityList.insert(entityList.end(), toAddList.begin(), toAddList.end());
		toAddList.clear();

		// very bad method! but works...
		for(auto d = toDelList.begin(); d != toDelList.end(); ++d){
			for(auto i = entityList.begin(); i != entityList.end(); i++){
				if(*i == *d){
					delete(*i);
					entityList.erase(i);
					break;
				}
			}
		}
		toDelList.clear();
		for(unsigned l = 0; l < 2; l++){
			for(auto i = entityList.begin(); i != entityList.end(); ++i){
				(*i)->render(l);
			}
		}
		
		renderer->update();
		ticks++;
	}


}

