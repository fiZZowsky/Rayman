#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <fstream>
#include <string>
#include <vector>

class MapLoader {
public:
    std::vector<std::pair< std::string, std::string> > objects;
    MapLoader();
    void loadMap(std::string mapID);
};

#endif // MAPLOADER_H
