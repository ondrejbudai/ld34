#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Game.hh"
#include "Player.hh"
#include "global.hh"
#include "Renderer.hh"
#include "InputHandler.hh"
#include "Enemy.hh"
#include "Star.hh"
#include "Menu.hh"

Game* Game::instance;

Game::Game(Renderer* renderer_) : GameState(renderer_){
	player = new Player(renderer);
	addEntity(player);

	inputHandler->registerKey(SDLK_UP, player);
	inputHandler->registerKey(SDLK_DOWN, player);
	inputHandler->registerKey(SDLK_w, player);	
	Game::instance = this;
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
	while(current->start == ticks){
		addEntity(new Enemy(renderer, GAME_W + current->x, GAME_H / 2 + current->y, current->vx, current->vy));
		current++;
	}
}

GameState* Game::update(){
	if(!inputHandler->update())
		return NULL;

	
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

	if(player->getHealth() <= 0)
		return new Menu(renderer);
	
	ticks++;

	return this;
}

void Game::render(){
	for(unsigned l = 0; l < 2; l++){
			for(auto i = entityList.begin(); i != entityList.end(); ++i){
				(*i)->render(l);
			}
		}
	
}
