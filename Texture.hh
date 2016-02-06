#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "Renderer.hh"

class Texture {
private:
	bool ok = false;
	Renderer& renderer;
	SDL_Texture* texture;
	int w, h;
	float scale = 1.0f;
	float angle = 0;
	int alpha = 255;
	SDL_Color* colormod = nullptr;

public:
	Texture(const char* filename, Renderer& renderer_);

	Texture(const Texture&& t) : renderer{t.renderer}, texture{t.texture}, w{t.w}, h{t.h} {
		ok = t.ok;
		scale = t.scale;
		angle = t.angle;
		alpha = t.alpha;
		colormod = t.colormod;
	}

	Texture(const Texture&) = delete;

	Texture& operator=(const Texture&) = delete;

	~Texture() { }

	void render(int x, int y) const;

	void render(int x, int y, int w, int h) const;

	void render(SDL_Rect* src, SDL_Rect* dest) const;

	void renderPart(int x, int y, SDL_Rect* src) const;

	void setAlpha(int alpha_) { alpha = alpha_; }
	void setAngle(float angle_){angle = angle_;}
	void setScale(float scale_){scale = scale_;}
	void setColorMod(SDL_Color* colormod_){colormod = colormod_;}

	bool isOk() const { return ok; }

	int getWidth() const { return w; }

	int getHeight() const { return h; }
};

#endif
