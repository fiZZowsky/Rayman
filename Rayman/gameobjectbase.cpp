#include "point2d.h"
#include "gameobjectbase.h"
#include "game_system.h"

Point2D GameObjectBase::GetPosition()
{
	return this->position;
}
