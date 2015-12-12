#ifndef ENEMY_HH
#define ENEMY_HH

#include "Entity.hh"
#include "Renderer.hh"
#include "Texture.hh"

class Enemy : public Entity {
	private:
		Renderer* renderer;
		Texture* texture;
		int x, y;
	public:
		Enemy(Renderer* renderer_, int x, int y);
		~Enemy(){}
		void render();
		bool colliding(int x, int y);
};

#endif
