#pragma once

class Character;

#include "collision_distances.h"
#include "gameobjectbase.h"
#include "game_system.h"

#define LEVEL_WIDTH 100
#define LEVEL_HEIGHT 12
#define TILE_WIDTH 50

class Level : public GameObjectBase
{
public:
	Level();

	void Draw() override;

	CollisionDistances CharacterCollides(Character* character);
	int PickUpCollectibles(Character* character);
	bool LevelExit(Character* character);

private:
	int levelMatrix[LEVEL_HEIGHT][LEVEL_WIDTH];
	int levelSolids[LEVEL_HEIGHT][LEVEL_WIDTH];
	int levelCollectible[LEVEL_HEIGHT][LEVEL_WIDTH];
	bool tileIsSolid(int tileNo);
	bool tileIsCollectible(int tileNo);

	int solids[34] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 14, 15, 16, 17, 18, 19, 20, 24, 25, 26, 27, 31, 32, 33, 34, 41, 42, 43, 44, 49, 50 };
	int collectibles[8] = { 54, 55, 56, 57, 61, 62, 63, 64 };

	ALLEGRO_BITMAP* tileSetImg;
	ALLEGRO_BITMAP* cloudsImg;
};

