#pragma once

class Character;

#include "collision_distances.h"
#include "gameplay.h"
#include "gameobjectbase.h"

#define ENEMY_WIDTH 50
#define ENEMY_HEIGHT 50

class Enemy : public GameObjectBase
{
public:
	Enemy(double initialX, double initialY, double maxX, int type);

	void Logic() override;
	void Draw() override;

	CollisionDistances CharacterCollides(Character* character);

private:
	ALLEGRO_BITMAP* enemySetImg;

	double min, max;

	int enemyType;

	bool forward;
};
