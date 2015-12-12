#ifndef GAME_HH
#define GAME_HH

#include "Entity.hh"
#include "Renderer.hh"
#include "Player.hh"
#include <vector>

class Game {
	private:
		Game();

		std::vector<Entity *> entityList;
		std::vector<Entity *> toAddList;
		std::vector<Entity *> toDelList;
		Renderer* renderer;
		Player* player;

		static Game* instance;
		void updateLevel(unsigned ticks);
	public:
		static Game* createInstance();
		static Game* getInstance();
		~Game();
		void run();
		void addEntity(Entity *e);
		void removeEntity(Entity *e);
		Entity* getColliding(Entity *e, int x, int y);
		Player* getPlayer(){return player;}
		
};

#endif
