#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "Renderer.hh"

class Texture {
private:
	bool ok = false;
	SDL_Texture* texture;
	int w, h;
	Renderer* renderer;
	float scale = 1.0f;
	float angle = 0;
	unsigned alpha = 255;
	SDL_Color* colormod = nullptr;

public:
	Texture(const char* filename, Renderer* renderer_);
	~Texture();
	void render(int x, int y);
	void render(int x, int y, int w, int h);
	void render(SDL_Rect* src, SDL_Rect* dest);
	void renderPart(int x, int y, SDL_Rect* src);

	void setAlpha(unsigned alpha_){alpha = alpha_;}
	void setAngle(float angle_){angle = angle_;}
	void setScale(float scale_){scale = scale_;}
	void setColorMod(SDL_Color* colormod_){colormod = colormod_;}

#ifdef ENABLE_TTF
	static Texture* createFromText(const char* filename, SDL_Color color, TTF_Font* font, Renderer* renderer_);
#endif

	bool isOk(){return ok;}
	int getWidth(){return w;}
	int getHeight(){return h;}
};

#endif
