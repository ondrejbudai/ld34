#ifndef GAME_HH
#define GAME_HH

#include "Entity.hh"
#include <vector>

class Game {
	private:
		Game();

		std::vector<Entity *> entityList;
		std::vector<Entity *> toAddList;
		std::vector<Entity *> toDelList;

		static Game* instance;
	public:
		static Game* createInstance();
		static Game* getInstance();
		~Game();
		void run();
		void addEntity(Entity *e);
		void removeEntity(Entity *e);
		Entity* getColliding(int x, int y);
		
};

#endif
