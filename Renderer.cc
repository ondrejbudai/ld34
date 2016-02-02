#include <iostream>
#include <SDL2/SDL_image.h>

#include "Renderer.hh"

bool Renderer::initialized = false;

Renderer::Renderer(int width_, int height_, const char *windowName){
	using namespace std;

	width = width_;
	height = height_;

	if(initialized){
		ok = false;
		cerr << "You can't initialize Renderer two times!" << endl;
		return;
	}
	ok = initialized = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
		ok = false;
		return;
	}

	window = SDL_CreateWindow(windowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (!window) {
		cerr << "SDL_Window could not initialize! SDL_Error: " << SDL_GetError() << endl;
		ok = false;
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		cerr << "SDL_Renderer could not initialize! SDL_Error: " << SDL_GetError() << endl;
		ok = false;
		return;
	}


	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_RenderClear(renderer);

	SDL_RendererInfo info;
	if(SDL_GetRendererInfo(renderer, &info) == 0){
		cout << "Renderer: " << info.name << endl;
	}

	int flags = IMG_INIT_PNG;

	if((IMG_Init(flags) & flags) != flags){
		cerr << "SDL_Image could not initialize! IMG_Error: " << IMG_GetError() << endl;
		ok = false;
		return;
	}

	cout << "SDL has been successfully initialized!" << endl;
}

Renderer::~Renderer(){
	for (auto& i : availableTextures) {
		if (i.second == nullptr) continue;
		SDL_DestroyTexture(i.second);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
}


void Renderer::update(){
	SDL_RenderPresent(renderer);
}

void Renderer::clear(){
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);
	SDL_RenderClear(renderer);
}

void Renderer::renderRect(int x, int y, int w, int h, SDL_Color col){
	SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a);
	SDL_Rect rect = {x + xoff, y + yoff, w, h};
	SDL_RenderFillRect(renderer, &rect);
}
