#ifndef ENTITY_hh
#define ENTITY_hh

#include "Texture.hh"

class Entity {
	protected:
		float x = 0, y = 0;
		float vx = 0, vy = 0;
		Texture* texture = nullptr;
		Renderer* renderer = nullptr;
		unsigned level = 0;
	public:
		virtual void update();
		virtual void render(unsigned l){if(texture && level == l) texture->render(x, y);}
		virtual ~Entity(){}
		virtual bool colliding(int x_, int y_);
		virtual bool colliding(Entity *e);
		virtual void damage(int amount){(void)amount;}
		virtual bool isEnemy(){return false;}
		int getX(){return x;}
		int getY(){return y;}
		int getW(){return texture->getWidth();}
		int getH(){return texture->getHeight();}
};

#endif
