#include "Star.hh"
#include "global.hh"

Star::Star(Renderer* renderer, int x_, int y_, float scale_, int alpha){
	texture = Texture::createFromFile("img/star.png", renderer);
	x = x_;
	y = y_;
	vx = -SCROLL_SPEED;
	SDL_SetTextureAlphaMod(*texture, alpha);
	scale = scale_;
}

void Star::render(unsigned l){
	if(l != 0) return;
	texture->renderScaled(x, y, scale);
}
