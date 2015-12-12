#include <iostream>
#include <SDL2/SDL_image.h>

#include "Renderer.hh"
#include "Texture.hh"

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

	window = SDL_CreateWindow(windowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if(window == NULL){
		cerr << "SDL_Window could not initialize! SDL_Error: " << SDL_GetError() << endl;
		ok = false;
		return;
	}
	//SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL){
		cerr << "SDL_Renderer could not initialize! SDL_Error: " << SDL_GetError() << endl;
		ok = false;
		return;
	}


	SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
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

	if(TTF_Init() == -1){
		cerr << "SDL_TTF could not initialize! SDL_Error: " << SDL_GetError() << endl;
		ok = false;
		return;
	}

	// font20 = TTF_OpenFont("Aero.ttf", 20);
	// font16 = TTF_OpenFont("Aero.ttf", 16);

	// if(!font16 || !font20){
	// 	cerr << "Font could not initialize! SDL_Error: " << SDL_GetError() << endl;
	// 	ok = false;
	// 	return;
	// }

	cout << "SDL has been successfully initialized!" << endl;
}

Renderer::~Renderer(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}


void Renderer::update(){
	SDL_RenderPresent(renderer);
}

void Renderer::clear(){
	SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderClear(renderer);
}

TTF_Font* Renderer::getFont(int size){
	if(size == 16){
		return font16;
	}
	return font20;
}

void Renderer::renderText(const char* text, TTF_Font* font, SDL_Color color, int x, int y, enum Align align){
	Texture* tex;

	tex = Texture::createFromText(text, color, font, this);

	tex->render((align == RIGHT) ? (width - x - tex->getWidth()) : x, y);

	delete tex;
}