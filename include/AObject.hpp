/*
** EPITECH PROJECT, 2020
** AObject.hpp
** File description:
** AObject.hpp
*/

#pragma once

#include <vector>

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
        AObject(int c, irr::core::vector3df(float, float, float) newPos);
        virtual ~AObject() = default;
        AObject::ObjectType getType(void) const;
        irr::core::vector3df(float, float, float) getPos(void) const;

    protected:
        AObject::ObjectType _type;
        std::pair<float, float> _pos;
};