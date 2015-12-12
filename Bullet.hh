#ifndef BULLET_HH
#define BULLET_HH

#include "Entity.hh"
#include "Renderer.hh"
#include "Texture.hh"

class Bullet : public Entity {
	private:
		bool isEnemy;
	public:
		Bullet(Renderer *Renderer_, int x_, int y_, int vx_, int vy_, bool isEnemy);
		~Bullet(){delete texture;}
		void update();
		bool colliding(int x_, int y_){(void)x_;(void)y_;return false;}
};

#endif
