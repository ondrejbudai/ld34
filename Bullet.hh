#ifndef BULLET_HH
#define BULLET_HH

#include "Entity.hh"
#include "Renderer.hh"
#include "Texture.hh"

class Bullet : public Entity {
	private:
		Renderer* renderer;
		Texture* texture;
		int x, y, vx, vy;
		bool isEnemy;
	public:
		Bullet(Renderer *Renderer_, int x_, int y_, int vx_, int vy_, bool isEnemy);
		~Bullet(){delete texture;}
		void update();
		void render();
};

#endif
