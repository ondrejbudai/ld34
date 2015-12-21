#include "Star.hh"
#include "global.hh"

Star::Star(Renderer* renderer, int x_, int y_, float scale, int alpha){
	texture = Texture::createFromFile("img/star.png", renderer);
	x = x_;
	y = y_;
	vx = -SCROLL_SPEED;
	texture->setAlpha(alpha);
	texture->setScale(scale);
}

void Star::render(unsigned l){
	if(l != 0) return;
	texture->render(x, y);
}
