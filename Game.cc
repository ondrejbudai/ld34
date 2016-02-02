#include <iostream>
#include <ctime>

#include "Game.hh"
#include "Enemy.hh"
#include "Star.hh"
#include "Menu.hh"

Game* Game::instance;

Game::Game(Renderer& renderer_) : GameState(renderer_), player(new Player(getNextId(), renderer_)) {
    addEntity(player);

    inputHandler.registerKey(SDLK_UP, player);
    inputHandler.registerKey(SDLK_DOWN, player);
    inputHandler.registerKey(SDLK_w, player);
    Game::instance = this;

    deathTex[0] = new Texture("img/deathscreen.png", renderer);
    deathTex[1] = new Texture("img/deathscreen2.png", renderer);

    victoryTex[0] = new Texture("img/victory1.png", renderer);
    victoryTex[1] = new Texture("img/victory2.png", renderer);
}

void Game::addEntity(Entity* e) {
    toAddList.push_back(e);
}

void Game::removeEntity(int id) {
    toDelList.push_back(id);
}

Entity* Game::getColliding(Entity& e, int x, int y) {
    for (auto& i : entityList) {
        if (i.first == e.id) continue;
        if (i.second->colliding(x, y))
            return i.second.get();
    }
    return nullptr;
}

void Game::updateLevel() {
    while (current->start <= ticks) {
        if (current->start < ticks) {
            current++;
            continue;
        }
        if (current->enemyType == E_END) {
            victory = 1;
            inputHandler.clearKeys();
            inputHandler.registerKey(SDLK_SPACE, this);
        } else {
            addEntity(new Enemy(getNextId(), renderer, GAME_W + current->x, GAME_H / 2 + current->y, current->vx,
                                current->vy));
        }
        current++;
    }
}

GameState* Game::update() {
    ticks++;
    if (!inputHandler.update()) {
        return nullptr;
    }
    if (close) {
        return new Menu(renderer);
    }

    if (player->getHealth() <= 0 || victory > 0) {
        return this;
    }

    for (auto& e : entityList) {
        e.second->update();
    }

    if (rand() % 15 == 0) {
        addEntity(new Star(getNextId(), renderer, GAME_W - 1, rand() % GAME_H, (rand() % 255 / 255.0f) * 0.75f + 0.25f,
                           rand() % 191));
    }

    updateLevel();

    for (auto e : toAddList) {
        entityList[e->id] = std::unique_ptr<Entity>(e);
    }
    toAddList.clear();

    for (auto id : toDelList) {
        entityList.erase(id);
    }
    toDelList.clear();

    if (player->getHealth() <= 0) {
        inputHandler.clearKeys();
        inputHandler.registerKey(SDLK_SPACE, this);
    }
    return this;
}

void Game::render() {

    for (unsigned l = 0; l < 3; l++) {
        for (auto& e : entityList) {
            e.second->render(l);
        }
    }
    if (victory > 0) {
        victoryTex[victory - 1]->render(WINDOW_W / 2, WINDOW_H / 2);
    } else if (player->getHealth() <= 0) {
        unsigned offset = (ticks / 10) % 2;
        deathTex[offset]->render(WINDOW_W / 2, WINDOW_H / 2);
    }
}

void Game::event(SDL_Event* e) {
    if (e->key.type == SDL_KEYUP) return;
    if (player->getHealth() <= 0 || victory == 2) close = true;
    if (victory == 1) victory = 2;
}
