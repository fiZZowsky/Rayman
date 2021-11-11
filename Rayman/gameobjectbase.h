#pragma once

#include "Point2D.h"

class GameObjectBase
{
public:

	virtual void Logic() {}

	virtual void Draw() {}

	Point2D GetPosition();

protected:
	Point2D position;
};

