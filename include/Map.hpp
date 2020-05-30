/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include "AObject.hpp"
#include <list>
#include <memory>
#include <iostream>
#include <fstream>
#include <irrlicht.h>
#include "driverChoice.h"
using namespace irr;
#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif

class Map {
    public:
        Map(scene::ISceneManager* smgr, video::IVideoDriver* driver);
        scene::IAnimatedMeshSceneNode* createObject(float posx, float posy, char c, scene::ISceneManager* smgr, video::IVideoDriver* driver);
        void core();
        void loadMap(scene::ISceneManager* smgr, video::IVideoDriver* driver);
        void displayMap(video::IVideoDriver* driver);
        void destroyObstacle();
        ~Map();

    protected:
    private:
        std::list<scene::IAnimatedMeshSceneNode *> _nodes;
        std::list<std::shared_ptr<AObject>> _list;
};

#endif /* !MAP_HPP_ */
