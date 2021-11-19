#pragma once

#include "game_system.h"
#include "level.h"
#include "enemy.h"
#include "character.h"
#include "hud.h"
#include <Windows.h>

class Gameplay : public game_system
{
public:
	Gameplay();
	~Gameplay();

	void KeyUp(WPARAM wParam);
	void KeyDown(WPARAM wParam);

	void Logic() override;

	static double offset;

private:
	Level* level;
	Character* character;
	Enemy* enemies[10];
	int noEnemies;
	HUD* hud;

	bool leftPressed;
	bool rightPressed;
	bool spacePressed;
};