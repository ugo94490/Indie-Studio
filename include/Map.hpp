/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include "Obstacle.hpp"
#include "Wall.hpp"
#include "Floor.hpp"
#include "Empty.hpp"
#include <list>
#include <memory>
#include <iostream>
#include <fstream>
#include "driverChoice.h"
#include "GeneratorMap.hpp"
#include "Exception.hpp"

class Map {
    public:
        Map(scene::ISceneManager* smgr, video::IVideoDriver* driver);
        void createObject(float posx, float posy, char c, scene::ISceneManager* smgr, video::IVideoDriver* driver);
        void loadMap(scene::ISceneManager* smgr, video::IVideoDriver* driver);
        ~Map();

    protected:
    private:
        std::list<std::shared_ptr<AObject>> _floor;
        std::list<std::shared_ptr<AObject>> _map;
};

#endif /* !MAP_HPP_ */
