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
#include <irrlicht.h>
#include "driverChoice.h"
using namespace irr;
#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif

class Map {
    public:
        Map(video::ITexture* driver);
        std::shared_ptr<AObject> createObject(float posx, float posy, char c) const;
        void core();
        void loadMap();
        void displayMap();
        ~Map();

    protected:
    private:
        video::ITexture* _Wall;
        video::ITexture* _Floor;
        video::ITexture* _Obstacle;
        std::list<std::shared_ptr<AObject>> _list;
};

#endif /* !MAP_HPP_ */
