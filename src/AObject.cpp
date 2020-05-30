/*
** EPITECH PROJECT, 2020
** AObject.cpp
** File description:
** AObject.cpp
*/

#include "AObject.hpp"

AObject::AObject(int c, irr::core::vector3df(float, float, float) newPos)
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

irr::core::vector3df(float, float, float) AObject::getPos(void) const
{
    return (_pos);
}