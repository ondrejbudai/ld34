#ifndef GAMESTATE_HH
#define GAMESTATE_HH

#include "Renderer.hh"

class GameState {
	public:
		virtual ~GameState(){}
		virtual GameState *run(){return NULL;}
};

#endif
