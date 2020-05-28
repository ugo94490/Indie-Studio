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
    if (c == 'X') {
        std::shared_ptr<AObject> ptr(new AObject(0, std::pair(posy, posx)));
        return ptr;
    }
    if (c == 'O') {
        std::shared_ptr<AObject> ptr(new AObject(1, std::pair(posy, posx)));
        return ptr;
    }
    if (c == ' ') {
        std::shared_ptr<AObject> ptr(new AObject(2, std::pair(posy, posx)));
        return ptr;
    }
    return NULL;
}

void Map::loadMap()
{
    std::string line;
    std::shared_ptr<AObject> ptr;
    std::ifstream myfile ("../assets/map.txt");

    if (!myfile.is_open())
        std::cout << ("Could not open map"); // a fix
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

void Map::displayMap(video::IVideoDriver* driver)
{
    int y = 32;
    int x = 32;

    for (auto it = _list.begin(); it != _list.end(); ++it) {
        if (it->get()->getType() == AObject::Wall)
            driver->draw2DImage(_Wall, core::position2d<s32>(x, y),
            core::rect<s32>(0,0,32,32), 0,
            video::SColor(255,255,255,255), true);
        if (it->get()->getType() == AObject::Floor)
            driver->draw2DImage(_Floor, core::position2d<s32>(x, y),
            core::rect<s32>(0,0,32,32), 0,
            video::SColor(255,255,255,255), true);
        if (it->get()->getType() == AObject::Obstacle)
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

Map::~Map()
{

}