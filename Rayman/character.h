#pragma once

#include "game_system.h"
#include "gameobjectbase.h"

#define CHARACTER_WIDTH 134
#define CHARACTER_HEIGHT 184
#define CHARACTER_TILE_HEIGHT 200

class Character : public GameObjectBase
{
public:
	Character();

	void Logic() override;
	void Draw() override;

	void StopFalling(double collisionSize);
	void Jump(bool fullJump);
	void BounceTop();
	void StopMovingLeft(double collisionSize);
	void StopMovingRight(double collisionSize);
	void Die();
	bool IsDead();
	void Reset();

	bool GoesLeft;
	bool GoesRight;

private:
	ALLEGRO_BITMAP* tileSetImg;

	Point2D speed;
	Point2D prevPosition;

	bool forward;
	bool dead;
};