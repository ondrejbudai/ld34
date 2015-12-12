#ifndef ENTITY_hh
#define ENTITY_hh

#include "Texture.hh"

class Entity {
	protected:
		int x = 0, y = 0;
		int vx = 0, vy = 0;
		Texture* texture = nullptr;
		Renderer* renderer = nullptr;
	public:
		virtual void update(){x += vx; y += vy;}
		virtual void render(){if(texture) texture->render(x, y);}
		virtual ~Entity(){}
		virtual bool colliding(int x_, int y_)
			{return x_ > x - texture->getWidth() / 2 && x_ < x + texture->getWidth() / 2 && y_ > y - texture->getHeight() / 2  && y_ < y + texture->getHeight() / 2;}
		virtual void damage(int amount){(void)amount;}
		virtual bool isEnemy(){return true;}
};

#endif
