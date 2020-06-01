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
        virtual ~AObject() = default;
        AObject::ObjectType getType(void) const;
        irr::core::vector3d<f32> getPos(void) const;

    protected:
        scene::IAnimatedMeshSceneNode * _node;
        AObject::ObjectType _type;
        irr::core::vector3d<f32> _pos;
};
