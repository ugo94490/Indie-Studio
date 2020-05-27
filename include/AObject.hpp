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
        AObject(AObject::ObjectType);
        virtual ~AObject() = 0;
        AObject::ObjectType getType(void);
        std::vector<float> getPos(void);

    protected:
        AObject::ObjectType type;
        std::vector<float> pos;
};
