#ifndef RENDERER_H_
#define RENDERER_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Renderer {
private:
	static bool initialized;
	SDL_Window* window;
	SDL_Renderer* renderer;
	TTF_Font* font16, *font20;
	bool ok;
	int height, width;
public:
enum Align {RIGHT, LEFT};
	Renderer(int width, int height, const char *windowName);
	~Renderer();
	void update();
	void clear();
	void renderText(const char* text, TTF_Font* font, SDL_Color color, int x, int y, enum Align align);
	void changeSize(int w, int h){width = w; height = h;}

	bool isOk(){return ok;}
	operator SDL_Renderer*() const {return renderer;}
	TTF_Font* getFont(int size);
	int getHeight(){return height;}
	int getWidth(){return width;}


	const SDL_Color cBlack = {0, 0, 0};
};

#endif