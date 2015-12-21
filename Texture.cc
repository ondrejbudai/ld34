#include <iostream>
#include <SDL2/SDL_image.h>

#include "Texture.hh"

Texture::Texture(SDL_Surface* from, Renderer* renderer_){
	using namespace std;

	ok = false;
	renderer = renderer_;

	texture = SDL_CreateTextureFromSurface(*renderer, from);
	if(texture == NULL){
		return;
	}
	if(SDL_QueryTexture(texture, NULL, NULL, &w, &h) != 0){
		SDL_DestroyTexture(texture);
		return;
	}

	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);

	ok = true;
}

void Texture::render(int x, int y){
	render(x, y, w * scale, h * scale);
}
void Texture::render(int x, int y, int w_, int h_){
	static SDL_Rect dest;

	dest.x = x - w_ / 2 + renderer->getXOffset();
	dest.y = y - h_ / 2 + renderer->getYOffset();
	dest.w = w_;
	dest.h = h_;

	render(NULL, &dest);
}

void Texture::render(SDL_Rect* src, SDL_Rect* dest){
	if(angle == 0)
		SDL_RenderCopy(*renderer, texture, src, dest);
	else
		SDL_RenderCopyEx(*renderer, texture, NULL, dest, angle, NULL, SDL_FLIP_NONE);
}

void Texture::renderPart(int x, int y, SDL_Rect* src){
	static SDL_Rect dest;
	dest.x = x - w / 2 + src->x + renderer->getXOffset();
	dest.y = y - h / 2 + src->y + renderer->getYOffset();
	dest.w = src->w;
	dest.h = src->h;

	render(src, &dest);
}

void Texture::setAlpha(unsigned alpha){
	SDL_SetTextureAlphaMod(texture, alpha);
}

void Texture::setColorMod(SDL_Color* color){
	SDL_SetTextureColorMod(texture, color->r, color->g, color->b);
}

Texture::~Texture(){
	SDL_DestroyTexture(texture);
}

Texture* Texture::createFromFile(const char* filename, Renderer* renderer_){
	using namespace std;

	SDL_Surface* surface = IMG_Load(filename);

	if(surface == NULL){
		cerr << "Image cannot be loaded: " << IMG_GetError() << endl;
		return NULL;
	}

	Texture* tex = new Texture(surface, renderer_);

	SDL_FreeSurface(surface);

	if(!tex->isOk()){
		cerr << "Cannot create texture from " << filename << " SDL_Error: " << SDL_GetError() << endl;
		return NULL;
	}
	return tex;
}

#ifdef ENABLE_TTF
Texture* Texture::createFromText(const char* text, SDL_Color color, TTF_Font* font, Renderer* renderer_){
	using namespace std;

	SDL_Surface* surface = TTF_RenderText_Blended(font, text, color);

	if(surface == NULL){
		cerr << "Image cannot be loaded: " << IMG_GetError() << endl;
		return NULL;
	}

	Texture* tex = new Texture(surface, renderer_);

	SDL_FreeSurface(surface);

	if(!tex->isOk()){
		cerr << "Cannot create texture from text \"" << text << "\" SDL_Error: " << SDL_GetError() << endl;
		return NULL;
	}
	return tex;
}
#endif


Texture* Texture::createFromSurface(SDL_Surface* surface, Renderer* renderer_){
	using namespace std;
	Texture* tex = new Texture(surface, renderer_);

	if(!tex->isOk()){
		cerr << "Cannot create texture from surface! SDL_Error: " << SDL_GetError() << endl;
		return NULL;
	}

	return tex;
}
