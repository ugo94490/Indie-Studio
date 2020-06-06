/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <iostream>
#include <fstream>
#include "driverChoice.h"
#include "GeneratorMap.hpp"
#include "Exception.hpp"
#include "Ground.hpp"
#include "SolidWall.hpp"
#include "BreakableWall.hpp"

class Map {
    public:
        Map(scene::ISceneManager* smgr, video::IVideoDriver* driver);
        ~Map();
        void createObject(float posx, float posy, char c, scene::ISceneManager* smgr, video::IVideoDriver* driver);
        void loadMap(scene::ISceneManager* smgr, video::IVideoDriver* driver);
        std::list<std::shared_ptr<GameObject>> getMap() const;

    protected:
    private:
        std::list<std::shared_ptr<GameObject>> _objs;
};

#endif /* !MAP_HPP_ */
