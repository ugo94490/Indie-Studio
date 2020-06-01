/*
** EPITECH PROJECT, 2020
** AObject.hpp
** File description:
** AObject.hpp
*/

#pragma once

#include <irrlicht.h>
#include "driverChoice.h"
#include <vector>
#include <utility>
using namespace irr;
#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif

class AObject
{
    public:
        enum ObjectType
        {
            Wall = 0,
            Floor = 1,
            Obstacle = 2
        };

        AObject() = default;
        AObject(char c, float posx, float posy, scene::ISceneManager* smgr, video::IVideoDriver* driver);
        virtual ~AObject() = default;
        AObject::ObjectType getType(void) const;
        void setType(char c, float posx, float posy, scene::ISceneManager* smgr, video::IVideoDriver* driver);
        std::pair<float, float> getPos(void) const;

    protected:
        scene::IAnimatedMeshSceneNode * _node;
        AObject::ObjectType _type;
        std::pair<float, float> _pos;
};