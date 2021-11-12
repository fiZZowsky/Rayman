#pragma once

#include "game_system.h"
#include "point2d.h"

class GameObjectBase
{
public:

	virtual void Logic() {}

	virtual void Draw() {}

	Point2D GetPosition();

	game_system* gameplay;

protected:
	Point2D position;
};

