/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Map
*/

#include "Map.hpp"

arcade::Map::Map()
{
    _map = {};
}

std::vector<std::string> arcade::Map::getMap(void)
{
    return (_map);
}

bool arcade::Map::openMap(std::string fileMap)
{
    std::vector<std::string> mapData;
    std::ifstream mapFile(fileMap);

    if (mapFile.is_open()) {
        std::string line;
        while (std::getline(mapFile, line))
            mapData.push_back(line);
        mapFile.close();
    } else {
        std::cout << "Unable to open file mapPacman.map" << std::endl;
        return (false);
    }
    _map = mapData;
    return (true);
}
