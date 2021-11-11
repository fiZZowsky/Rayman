#pragma once

#include "GameObjectBase.h"
#include "game_system.h"

class HUD : public GameObjectBase
{
public:
    HUD();

    void Draw() override;

    void AddCoins(int addCoins);
    void RemoveLife();
    bool HasLives();
    void FinishedLevel();

private:
    ALLEGRO_BITMAP* tileSetImg;
    ALLEGRO_BITMAP* charSetImg;
    /*
    IDWriteFactory* m_pDWriteFactory;
    IDWriteTextFormat* m_pTextFormat1;
    IDWriteTextFormat* m_pTextFormat2;
    ID2D1SolidColorBrush* m_pWhiteBrush;*/

    int lives;
    int coins;
    bool success;
};
