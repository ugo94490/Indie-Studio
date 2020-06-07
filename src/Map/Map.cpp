/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** map
*/

#include "Map.hpp"

Map::Map(scene::ISceneManager *smgr, video::IVideoDriver *driver)
{
    GeneratorMap gene(17, 16);
    loadMap(smgr, driver);
}

Map::~Map()
{
}

void Map::createObject(float posy, float posx, char c, scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    if (c == 'X') {
        std::shared_ptr<GameObject> objptr = std::make_shared<SolidWall>(posx, 40, posy, smgr, driver);
        _objs.push_back(objptr);
    }
    if (c == 'O') {
        std::shared_ptr<GameObject> objptr = std::make_shared<BreakableWall>(posx, 40, posy, smgr, driver);
        _objs.push_back(objptr);
    }
    std::shared_ptr<GameObject> objptr = std::make_shared<Ground>(posx, 0, posy, smgr, driver);
    _objs.push_back(objptr);
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
            createObject(float(j) * 40.0, float(i) * 40.0, line[j], smgr, driver);
    }
    myfile.close();
}

std::list<std::shared_ptr<GameObject>> Map::getMap() const
{
    return (_objs);
}