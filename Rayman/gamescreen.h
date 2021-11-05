#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "game_system.h"
#include "character.h"
#include "map.h"

class GameScreen {
private:
    Character* character;
    Map* map;
    float currentX = gameWidth;
protected:
    InputManager input;
public:
    GameScreen(SoundManager* sound);

    void loadContent();
    void unloadContent();
    void update(ALLEGRO_EVENT event);
    void draw();
    void checkCollides();
};

#endif // GAMESCREEN_H
