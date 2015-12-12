#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "Renderer.hh"

class Texture {
private:
	Texture(SDL_Surface* from, const Renderer* renderer_);
	bool ok;
	SDL_Texture* texture;
	int w, h;
	const Renderer* renderer;
public:
	~Texture();
	void render(int x, int y);
	void render(int x, int y, int w, int h);
	void renderScaled(int x, int y, double scale);
	void renderShaded(int x, int y, int w_, int h_, int r, int g, int b);

	static Texture* createFromFile(const char* filename, const Renderer* renderer_);
	static Texture* createFromText(const char* filename, SDL_Color color, TTF_Font* font, const Renderer* renderer_);
	static Texture* createFromSurface(SDL_Surface* surface, const Renderer* renderer_);

	bool isOk(){return ok;}
	operator SDL_Texture*() {return texture;}
	int getWidth(){return w;}
	int getHeight(){return h;}
};

#endif