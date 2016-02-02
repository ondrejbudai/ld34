#ifndef GAMESTATE_HH
#define GAMESTATE_HH

#include "Renderer.hh"
#include "InputHandler.hh"

class GameState {
protected:
    Renderer& renderer;
    InputHandler inputHandler;
public:
    GameState(Renderer& renderer_) : renderer(renderer_), inputHandler() { }

    GameState(const GameState&) = delete;

    GameState& operator=(const GameState&) = delete;

    virtual ~GameState() { }

    virtual GameState* update() { return nullptr; }

    virtual void render() { }
};

#endif
