#ifndef GAMESTATE_HH
#define GAMESTATE_HH

#include "Renderer.hh"
#include "InputHandler.hh"

class GameState {
	protected:
		InputHandler* inputHandler;
		Renderer* renderer;
	public:
		GameState(Renderer* renderer_){inputHandler = new InputHandler(); renderer = renderer_;}
		virtual ~GameState(){}
		virtual GameState *update(){return NULL;}
		virtual void render(){}
};

#endif
