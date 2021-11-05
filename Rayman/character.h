#ifndef CHARACTER_H
#define CHARACTER_H

#include "gameobjects.h"
#include "inputmanager.h"
#include "soundmanager.h"

class Character : public GameObjects {
private:
    SoundManager* sound;

    ALLEGRO_BITMAP* image;
    enum CharacterType { Big, Small };
    CharacterType type;
    Rectangle* stand, * walk[3], * run, * hang[2], * crouchOrDie;
    Rectangle* currentFrame;
    int rightOrLeftFlag = 0; // right = 0, left = 1
    float jumpSpeed, moveSpeed;
    bool isOnAir = false;
    float frameChangeSpeed = 0.5;
    float currentFrameNumber = 0;
    bool isObstacleOnTop = false, isObstacleOnBottom = false, isObstacleOnRight = false, isObstacleOnLeft = false;

    void initCharacterRects();

public:
    enum Direction { Up, Down, Left, Right };
    Direction dir;

    Character(SoundManager* sound);

    void loadContent();
    void unloadContect();
    void update(ALLEGRO_EVENT event, InputManager input);
    void draw();
    bool haveCollideWith(GameObjects* obj);
    void collide(GameObjects* obj);
};

#endif // CHARACTER_H
