/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** map
*/

#include "Map.hpp"

Map::Map(scene::ISceneManager *smgr, video::IVideoDriver *driver)
{
    GeneratorMap gene(17, 17);
    loadMap(smgr, driver);
}

void Map::createObject(float posx, float posy, char c, scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    if (c == 'X') {
        std::shared_ptr<AObject> ptr(new Wall(posx, posy, smgr, driver));
        _map.push_back(ptr);
    }
    if (c == 'O') {
        std::shared_ptr<AObject> ptr(new Obstacle(posx, posy, smgr, driver));
        _map.push_back(ptr);
    }
    if (c == ' ') {
        std::shared_ptr<AObject> ptr(new Empty(posx, posy));
        _map.push_back(ptr);
    }
     std::shared_ptr<AObject> ptr(new Floor(posx, posy, smgr, driver));
    _floor.push_back(ptr);
}

void Map::loadMap(scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    std::string line;
    std::ifstream myfile ("assets/map/random_map.txt");

    if (!myfile.is_open())
        throw(Exception("Je sais pas open une map\n"));
    for (int i = 0; !myfile.eof(); i++) {
        getline (myfile, line);
        for (int j = 0; line[j]; j++)
            createObject(float(j) * 8.0, float(i) * 8.0, line[j], smgr, driver);
    }
    myfile.close();
}

Map::~Map()
{

}