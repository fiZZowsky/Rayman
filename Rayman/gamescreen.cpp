#include "gamescreen.h"
#include <iostream>

GameScreen::GameScreen(SoundManager *sound) {
    character = new Character(sound);
    map = new Map("1");
}

void GameScreen::loadContent() {

}

void GameScreen::unloadContent() {

}

void GameScreen::update(ALLEGRO_EVENT event) {
    map->update(event);
    character->update(event, input);
}

void GameScreen::draw() {
    map->draw();
    character->draw();
}

void GameScreen::checkCollides() {
    bool thereIsAtLeastOneCollide = false;
    for (std::vector<GameObjects*>::iterator itr = map->objects->begin(); itr != map->objects->end(); itr++) {
        if (character->haveCollideWith(*itr)) {
            thereIsAtLeastOneCollide = true;
            character->collide(*itr);
            (*itr)->collide(character);
        }
    }
    if (!thereIsAtLeastOneCollide) {
        character->activeGravity = true;
    }
    if (character->box->right > gameWidth / 4 * 3) {
        if (currentX <= 3390 * SCALE) {
            if (character->velocity.first > 0) {
                map->moveMapToLeft();
                character->box->updateWithRight(gameWidth / 4 * 3);
            }
        } else
            currentX = 3392 * SCALE;
        currentX += 5;
    }
}
