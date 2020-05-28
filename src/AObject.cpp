/*
** EPITECH PROJECT, 2020
** AObject.cpp
** File description:
** AObject.cpp
*/

#include "AObject.hpp"

AObject::AObject(int c, std::pair<float, float> newPos)
{
    if (c == 0)
        _type = Wall;
    if (c == 1)
        _type = Floor;
    if (c == 2)
        _type = Obstacle;
    _pos = newPos;
}

AObject::ObjectType AObject::getType(void) const
{
    return (_type);
}

std::pair<float, float> AObject::getPos(void) const
{
    return (_pos);
}