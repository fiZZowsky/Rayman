#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include "game_system.h"

class SoundManager {
private:
    ALLEGRO_SAMPLE* theme, * jump_small, * jump_big, * die;
    ALLEGRO_SAMPLE_ID themeID;
public:
    SoundManager();
    void playTheme();
    void playJumpSmall();
    void playJumpBig();
    void PlayPlayerDie();
};

#endif // SOUNDMANAGER_H
