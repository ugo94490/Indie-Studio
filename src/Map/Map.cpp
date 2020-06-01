/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** map
*/

#include "Map.hpp"

Map::Map(scene::ISceneManager *smgr, video::IVideoDriver *driver)
{
    loadMap(smgr, driver);
}

std::shared_ptr<AObject> Map::createObject(float posx, float posy, char c, scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    if (c == 'X') {
        std::shared_ptr<AObject> ptr(new Wall(posx, posy, smgr, driver));
        return ptr;
    }
    if (c == 'O') {
        std::shared_ptr<AObject> ptr(new Obstacle(posx, posy, smgr, driver));
        return ptr;
    }
    if (c == ' ') {
        std::shared_ptr<AObject> ptr(new Floor(posx, posy, smgr, driver));
        return ptr;
    }
    return NULL;
}

void Map::loadMap(scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    std::string line;
    std::shared_ptr<AObject> ptr;
    std::ifstream myfile ("assets/map/random_map.txt");

    if (!myfile.is_open())
        std::cout << "Could not open map\n"; // a fix
    for (int i = 0; !myfile.eof(); i++) {
        getline (myfile, line);
        for (int j = 0; line[j]; j++) {
            ptr = createObject(float(j) * 8.0, float(i) * 8.0, line[j], smgr, driver);
            if (ptr)
                _list.push_back(ptr);
        }
    }
    myfile.close();
}

void Map::destroyObstacle()
{

}

void Map::displayMap(video::IVideoDriver* driver)
{

}

void Map::core()
{

}

Map::~Map()
{

}