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
#include <list>
#include <memory>
#include <iostream>
#include <fstream>
#include "driverChoice.h"


class Map {
    public:
        Map(scene::ISceneManager* smgr, video::IVideoDriver* driver);
        std::shared_ptr<AObject> createObject(float posx, float posy, char c, scene::ISceneManager* smgr, video::IVideoDriver* driver);
        void core();
        void loadMap(scene::ISceneManager* smgr, video::IVideoDriver* driver);
        void displayMap(video::IVideoDriver* driver);
        void destroyObstacle();
        ~Map();

    protected:
    private:
        std::list<std::shared_ptr<AObject>> _list;
};

#endif /* !MAP_HPP_ */
