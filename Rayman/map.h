#ifndef MAP_H
#define MAP_H

#include "maploader.h"
#include "gameobjects.h"
#include "position.h"
#include "objects.h"
#include <string>

class Map {
private:
    MapLoader loader;
    const static int numOfObjects = 30;
    std::string objectNames[numOfObjects];

    void initObjectNames();
public:
    std::vector<GameObjects*>* objects;
    Map(std::string mapID);

    void update(ALLEGRO_EVENT event);
    void draw();
    void moveMapToLeft();
};

#endif // MAP_H
