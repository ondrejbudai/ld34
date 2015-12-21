#ifndef STAR_HH
#define STAR_HH

#include "Entity.hh"
#include <iostream>

class Star : public Entity {
	private:
	public:
		Star(Renderer* renderer, int x_, int y_, float scale, int alpha);
		~Star(){delete texture;}
		bool colliding(int x_, int y_){(void)x_;(void)y_;return false;}
		bool colliding(Entity *e){(void)e;return false;}
		void render(unsigned l);
};

#endif
