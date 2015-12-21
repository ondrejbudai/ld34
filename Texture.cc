#include <iostream>
#include <SDL2/SDL_image.h>

#include "Texture.hh"

Texture::Texture(const char* filename, Renderer* renderer_){
	using namespace std;

	renderer = renderer_;
	texture = renderer->getTexture(filename);
	if(texture == NULL){
		SDL_Surface* surface = IMG_Load(filename);

		if(surface == NULL){
			cerr << "Image cannot be loaded: " << IMG_GetError() << endl << "Failed image: " << filename << endl;
			return;
		}

		texture = SDL_CreateTextureFromSurface(*renderer, surface);
		if(texture == NULL){
			cerr << "Texture cannot be created: " << SDL_GetError() << endl << "Failed image: " << filename << endl;
			return;
		}

		SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
		SDL_FreeSurface(surface);
		
		renderer->addTexture(filename, texture);
	}

	if(SDL_QueryTexture(texture, NULL, NULL, &w, &h) != 0){
		SDL_DestroyTexture(texture);
		cerr << "Texture query failed: " << SDL_GetError() << endl << "Failed image: " << filename << endl;
		return;
	}

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
	SDL_SetTextureAlphaMod(texture, alpha);
	if(colormod == nullptr)
		SDL_SetTextureColorMod(texture, 255, 255, 255);
	else
		SDL_SetTextureColorMod(texture, colormod->r, colormod->g, colormod->b);

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

	SDL_SetTextureAlphaMod(texture, alpha);
	if(colormod == nullptr)
		SDL_SetTextureColorMod(texture, 255, 255, 255);
	else
		SDL_SetTextureColorMod(texture, colormod->r, colormod->g, colormod->b);
		

	render(src, &dest);
}

Texture::~Texture(){
	// SDL_DestroyTexture(texture);
}
