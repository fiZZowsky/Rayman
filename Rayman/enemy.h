#pragma once

class Character;

#include "collision_distances.h"

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
	//ID2D1Bitmap* enemySetImg;

	double min, max;

	int enemyType;

	bool forward;
};
