#ifndef GAME_HH
#define GAME_HH

#include <vector>
#include <unordered_map>
#include <memory>
#include "GameState.hh"
#include "Entity.hh"
#include "Renderer.hh"
#include "Player.hh"
#include "Levels.hh"
#include "Listeners.hh"

class Game : public GameState, public Listener {

private:
    int nextId = 0;
    Player* player;
    std::unordered_map<int, std::unique_ptr<Entity>> entityList{};
    std::vector<Entity*> toAddList{};
    std::vector<int> toDelList{};
    Level* current = levels;
    unsigned ticks = 0;
    bool close = false;
    unsigned victory = 0;
    Texture* deathTex[2];
    Texture* victoryTex[2];


    void updateLevel();

    static Game* instance;
public:
    Game(Renderer& renderer_);

    Game(const Game&) = delete;

    Game& operator=(const Game&) = delete;

    ~Game() { }

    GameState* update();

    void render();

    int getNextId() { return nextId++; }

    void event(SDL_Event* e);

    void addEntity(Entity* e);

    void removeEntity(int id);

    Entity* getColliding(Entity& e, int x, int y);

    Player& getPlayer() { return *player; }

    static Game* getInstance() { return Game::instance; }

};

#endif
