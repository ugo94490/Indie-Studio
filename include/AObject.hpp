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
        AObject(AObject::ObjectType, std::pair<float, float> newPos);
        virtual ~AObject() = default;
        AObject::ObjectType getType(void) const;
        std::pair<float, float> getPos(void) const;

    protected:
        AObject::ObjectType type;
        std::pair<float, float> pos;
};