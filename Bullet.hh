#ifndef BULLET_HH
#define BULLET_HH

#include "Entity.hh"
#include "Renderer.hh"
#include "Texture.hh"

class Bullet : public Entity {
	private:
		Renderer* renderer;
		Texture* texture;
		int x, y;
	public:
		Bullet(Renderer *Renderer_, int x_, int y_);
		~Bullet();
		void update();
		void render();
};

#endif
