#include "collision_distances.h"
#include "character.h"
#include "level.h"
#include "gameplay.h"

Level::Level()
{
	// Default nothing map
	for (int i = 0; i < LEVEL_HEIGHT; i++)
	{
		for (int j = 0; j < LEVEL_WIDTH; j++)
		{
			levelMatrix[i][j] = -1;
			levelSolids[i][j] = false;
			levelCollectible[i][j] = false;
		}
	}

	// Load map from file
	std::ifstream myfile("res/map/level.txt");

	if (myfile.is_open())
	{
		for (int i = 0; i < LEVEL_HEIGHT; i++)
		{
			for (int j = 0; j < LEVEL_WIDTH; j++)
			{
				myfile >> levelMatrix[i][j];
				levelSolids[i][j] = tileIsSolid(levelMatrix[i][j]);
				levelCollectible[i][j] = tileIsCollectible(levelMatrix[i][j]);
			}
		}
	}
}

void Level::Draw()
{
	ALLEGRO_BITMAP* cloudsRect1;
	ALLEGRO_BITMAP* cloudsRect2;
	ALLEGRO_BITMAP* rectangle1;
	ALLEGRO_BITMAP* rectangle2;

	// Loads images if needed
	if (tileSetImg == NULL)
	{
		tileSetImg = gamplay->LoadImageW("res/map/tileset.png");
	}

	if (cloudsImg == NULL)
	{
		cloudsImg = gameplay->LoadImageW("res/map/clouds.png");
	}

	// Draw the Clouds, but only offset them by half, to implement parallaxing
	double start_x = gameplay::offset / 2.0;
	while (start_x > gameWidth)
	{
		start_x -= gameWidth;
	}
	cloudsRect1 = al_draw_filled_rectangle(
		0 - start_x, 0,
		gameWidth - start_x, gameHeight
	);
	cloudsRect2 = al_draw_filled_rectangle(
		gameWidth - start_x, 0,
		2 * gameWidth - start_x, gameHeight
	);
	m_pRenderTarget->DrawBitmap(cloudsImg, cloudsRect1);
	m_pRenderTarget->DrawBitmap(cloudsImg, cloudsRect2);

	// Draw level tiles
	for (int i = 0; i < LEVEL_HEIGHT; i++)
	{
		for (int j = 0; j < LEVEL_WIDTH; j++)
		{
			if ((j + 1) * TILE_WIDTH >= Gameplay::offset && j * TILE_WIDTH < Gameplay::offset + gameWidth)
			{
				if (levelMatrix[i][j] != -1)
				{
					rectangle1 = al_draw_filled_rectangle(
						j * TILE_WIDTH - Gameplay::offset, i * TILE_WIDTH,
						(j + 1) * TILE_WIDTH - Gameplay::offset + 1, (i + 1) * TILE_WIDTH
					);

					int posY = levelMatrix[i][j] / 7;
					int posX = levelMatrix[i][j] % 7;

					rectangle2 = al_draw_filled_rectangle(
						posX * TILE_WIDTH, posY * TILE_WIDTH,
						posX * TILE_WIDTH + TILE_WIDTH - 1, posY * TILE_WIDTH + TILE_WIDTH - 1
					);

					m_pRenderTarget->DrawBitmap(tileSetImg, rectangle1, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR, rectangle2);
				}
			}
		}
	}
}

CollisionDistances Level::CharacterCollides(Character* character)
{
	// this returns collision details between the character and the tiles
	int noCollisions = 0;
	CollisionDistances collisions[9];

	CollisionDistances cummulatedCollision;
	cummulatedCollision.top = 0;
	cummulatedCollision.bottom = 0;
	cummulatedCollision.left = 0;
	cummulatedCollision.right = 0;

	double charTop = character->GetPosition().y - CHARACTER_HEIGHT;
	double charBottom = character->GetPosition().y;
	double charLeft = character->GetPosition().x - CHARACTER_WIDTH / 2 + 3;
	double charRight = character->GetPosition().x + CHARACTER_WIDTH / 2 - 4;

	// only check the tiles that the character is close to
	int startX = (int)(charLeft / TILE_WIDTH);
	if (startX < 0)
		startX = 0;
	int startY = (int)(charTop / TILE_WIDTH);
	if (startY < 0)
		startY = 0;
	int endX = (int)(charRight / TILE_WIDTH);
	if (endX > LEVEL_WIDTH - 1)
		endX = LEVEL_WIDTH - 1;
	int endY = (int)(charBottom / TILE_WIDTH);
	if (endY > LEVEL_HEIGHT - 1)
		endY = LEVEL_HEIGHT - 1;

	for (int i = startY; i <= endY; i++)
	{
		for (int j = startX; j <= endX; j++)
		{
			if (levelSolids[i][j])
			{
				double tileTop = i * TILE_WIDTH;
				double tileBottom = (i + 1) * TILE_WIDTH - 1;
				double tileLeft = j * TILE_WIDTH;
				double tileRight = (j + 1) * TILE_WIDTH - 1;

				// If it's a collision
				if (charTop < tileBottom && charBottom > tileTop && charRight > tileLeft && charLeft < tileRight)
				{
					// add this collision to the list
					collisions[noCollisions].top = abs(charTop - tileBottom);
					collisions[noCollisions].bottom = abs(charBottom - tileTop);
					collisions[noCollisions].left = abs(charLeft - tileRight);
					collisions[noCollisions].right = abs(charRight - tileLeft);

					collisions[noCollisions].keepSmallest();

					// add the collision details to the cummulated collision
					cummulatedCollision.top += collisions[noCollisions].top;
					cummulatedCollision.bottom += collisions[noCollisions].bottom;
					cummulatedCollision.left += collisions[noCollisions].left;
					cummulatedCollision.right += collisions[noCollisions].right;

					noCollisions++;
				}
			}
		}
	}

	// whichever side collides the most, that side is taken into consideration
	cummulatedCollision.keepLargest();
	if (cummulatedCollision.top != 0)
	{
		cummulatedCollision.top = 0;
		for (int i = 0; i < noCollisions; i++)
		{
			cummulatedCollision.top = fmax(cummulatedCollision.top, collisions[i].top);
		}
	}
	if (cummulatedCollision.bottom != 0)
	{
		cummulatedCollision.bottom = 0;
		for (int i = 0; i < noCollisions; i++)
		{
			cummulatedCollision.bottom = fmax(cummulatedCollision.bottom, collisions[i].bottom);
		}
	}
	if (cummulatedCollision.left != 0)
	{
		cummulatedCollision.left = 0;
		for (int i = 0; i < noCollisions; i++)
		{
			cummulatedCollision.left = fmax(cummulatedCollision.left, collisions[i].left);
		}
	}
	if (cummulatedCollision.right != 0)
	{
		cummulatedCollision.right = 0;
		for (int i = 0; i < noCollisions; i++)
		{
			cummulatedCollision.right = fmax(cummulatedCollision.right, collisions[i].right);
		}
	}

	return cummulatedCollision;
}

int Level::PickUpCollectibles(Character* character)
{
	// this method checks for collisions with coins and returns the number
	int noCollisions = 0;

	double charTop = character->GetPosition().y - CHARACTER_HEIGHT;
	double charBottom = character->GetPosition().y;
	double charLeft = character->GetPosition().x - CHARACTER_WIDTH / 2 + 3;
	double charRight = character->GetPosition().x + CHARACTER_WIDTH / 2 - 4;

	int startX = (int)(charLeft / TILE_WIDTH);
	if (startX < 0)
		startX = 0;
	int startY = (int)(charTop / TILE_WIDTH);
	if (startY < 0)
		startY = 0;
	int endX = (int)(charRight / TILE_WIDTH);
	if (endX > LEVEL_WIDTH - 1)
		endX = LEVEL_WIDTH - 1;
	int endY = (int)(charBottom / TILE_WIDTH);
	if (endY > LEVEL_HEIGHT - 1)
		endY = LEVEL_HEIGHT - 1;

	for (int i = startY; i <= endY; i++)
	{
		for (int j = startX; j <= endX; j++)
		{
			if (levelCollectible[i][j])
			{
				double tileTop = i * TILE_WIDTH;
				double tileBottom = (i + 1) * TILE_WIDTH - 1;
				double tileLeft = j * TILE_WIDTH;
				double tileRight = (j + 1) * TILE_WIDTH - 1;

				// If it's a collision
				if (charTop < tileBottom && charBottom > tileTop && charRight > tileLeft && charLeft < tileRight)
				{
					noCollisions++;
					levelMatrix[i][j] = -1; // remove the coin by resetting the tile position
					levelCollectible[i][j] = false;
				}
			}
		}
	}

	return noCollisions;
}

bool Level::LevelExit(Character* character)
{
	// returns true if the character collides with the level exit portal
	int noCollisions = 0;

	double charTop = character->GetPosition().y - CHARACTER_HEIGHT;
	double charBottom = character->GetPosition().y;
	double charLeft = character->GetPosition().x - CHARACTER_WIDTH / 2 + 3;
	double charRight = character->GetPosition().x + CHARACTER_WIDTH / 2 - 4;

	int startX = (int)(charLeft / TILE_WIDTH);
	if (startX < 0)
		startX = 0;
	int startY = (int)(charTop / TILE_WIDTH);
	if (startY < 0)
		startY = 0;
	int endX = (int)(charRight / TILE_WIDTH);
	if (endX > LEVEL_WIDTH - 1)
		endX = LEVEL_WIDTH - 1;
	int endY = (int)(charBottom / TILE_WIDTH);
	if (endY > LEVEL_HEIGHT - 1)
		endY = LEVEL_HEIGHT - 1;

	for (int i = startY; i <= endY; i++)
	{
		for (int j = startX; j <= endX; j++)
		{
			if (levelMatrix[i][j] == 11)
			{
				double tileTop = i * TILE_WIDTH;
				double tileBottom = (i + 1) * TILE_WIDTH - 1;
				double tileLeft = j * TILE_WIDTH;
				double tileRight = (j + 1) * TILE_WIDTH - 1;

				// If it's a collision
				if (charTop < tileBottom && charBottom > tileTop && charRight > tileLeft && charLeft < tileRight)
				{
					return true;
				}
			}
		}
	}

	return false;
}

bool Level::tileIsSolid(int tileNo)
{
	for (int i = 0; i < 34; i++)
	{
		if (solids[i] == tileNo)
		{
			return true;
		}
	}
	return false;
}

bool Level::tileIsCollectible(int tileNo)
{
	for (int i = 0; i < 8; i++)
	{
		if (collectibles[i] == tileNo)
		{
			return true;
		}
	}
	return false;
}