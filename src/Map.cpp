/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** map
*/

#include "Map.hpp"

Map::Map(video::IVideoDriver* driver)
{
    _Wall = driver->getTexture("assets/textures/grass.png");
    _Floor = driver->getTexture("assets/textures/cave_ground.png");
    _Obstacle = driver->getTexture("assets/textures/water.png");
    loadMap();
}

std::shared_ptr<AObject> Map::createObject(float posx, float posy, char c) const
{
    if (c != 'X' && c != 'O' && c != ' ')
        return NULL;
    if (c == 'X')
        std::shared_ptr<AObject> ptr(new AObject(AObject::Wall, std::pair(posy, posx)));
    if (c == 'O')
        std::shared_ptr<AObject> ptr(new AObject(AObject::Obstacle, std::pair(posy, posx)));
    if (c == ' ')
        std::shared_ptr<AObject> ptr(new AObject(AObject::Floor, std::pair(posy, posx)));
    return (ptr);
}

void Map::loadMap()
{
    std::string line;
    ifstream myfile ("./assets/map.txt");

    if (!myfile.is_open())
        throw(Exception ("Could not open map"));
    for (int i = 0; !myfile.eof(); i++) {
        getline (myfile, line);
        for (int j = 0; line[j]; j++) {
            ptr = createObject(float(j) * 32.0, float(i) * 32.0, line[j]);
            if (ptr)
                _list.push_front(ptr);
        }
    }
    myfile.close();
}

void Map::displayMap()
{
    int y = 32;
    int x = 32;

    for (auto chara : _list) {
        if (chara.getType() == ObjectType::Wall)
            driver->draw2DImage(_Wall, core::position2d<s32>(x, y),
            core::rect<s32>(0,0,32,32), 0,
            video::SColor(255,255,255,255), true);
        if (chara.getType() == ObjectType::Floor)
            driver->draw2DImage(_Floor, core::position2d<s32>(x, y),
            core::rect<s32>(0,0,32,32), 0,
            video::SColor(255,255,255,255), true);
        if (chara.getType() == ObjectType::Obstacle)
            driver->draw2DImage(_Obstacle, core::position2d<s32>(x, y),
            core::rect<s32>(0,0,32,32), 0,
            video::SColor(255,255,255,255), true);
        x += 32;
        y += 32;
    }
}

void Map::core()
{

}

~Map::Map()
{

}