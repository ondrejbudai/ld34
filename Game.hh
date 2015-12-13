#ifndef GAME_HH
#define GAME_HH

#include <vector>
#include "GameState.hh"
#include "Entity.hh"
#include "Renderer.hh"
#include "Player.hh"

class Game : public GameState {

	private:
		std::vector<Entity *> entityList;
		std::vector<Entity *> toAddList;
		std::vector<Entity *> toDelList;
		Renderer* renderer;
		Player* player;
		void updateLevel(unsigned ticks);
		static Game* instance;
	public:
		Game(Renderer* renderer_);
		~Game(){}
		GameState* run();
		void addEntity(Entity *e);
		void removeEntity(Entity *e);
		Entity* getColliding(Entity *e, int x, int y);
		Player* getPlayer(){return player;}
		static Game* getInstance(){return Game::instance;}
		
};

#endif
