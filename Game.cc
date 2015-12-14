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

	deathTex[0] = Texture::createFromFile("img/deathscreen.png", renderer);
	deathTex[1] = Texture::createFromFile("img/deathscreen2.png", renderer);

	victoryTex[0] = Texture::createFromFile("img/victory1.png", renderer);
	victoryTex[1] = Texture::createFromFile("img/victory2.png", renderer);
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
	while(current->start <= ticks){
		if(current->start < ticks){
			current++;
			continue;
		}
		if(current->enemyType == E_END){
			victory = 1;
			inputHandler->clearKeys();
			inputHandler->registerKey(SDLK_SPACE, this);
		}
		addEntity(new Enemy(renderer, GAME_W + current->x, GAME_H / 2 + current->y, current->vx, current->vy));
		current++;
	}
}

GameState* Game::update(){
	if(!inputHandler->update())
		return NULL;
	if(close)
		return new Menu(renderer);

	if(player->getHealth() <= 0 || victory > 0)
		return this;

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

	if(player->getHealth() <= 0){
		inputHandler->clearKeys();
		inputHandler->registerKey(SDLK_SPACE, this);
	}
	
	ticks++;

	return this;
}

void Game::render(){
	static unsigned ticks = 0;

	for(unsigned l = 0; l < 2; l++){
		for(auto i = entityList.begin(); i != entityList.end(); ++i){
			(*i)->render(l);
		}
	}
	if(victory > 0){
		victoryTex[victory - 1]->render(WINDOW_W / 2, WINDOW_H / 2);
	} else if(player->getHealth() <= 0){
		unsigned offset = (ticks / 10) % 2;
		deathTex[offset]->render(WINDOW_W / 2, WINDOW_H / 2);
	}


	ticks++;
}

void Game::event(SDL_Event* e){
	if(e->key.type == SDL_KEYUP) return;
	if(player->getHealth() <= 0 || victory == 2) close = true;
	if(victory == 1) victory = 2;
}
