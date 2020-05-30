/*
** EPITECH PROJECT, 2020
** AObject.cpp
** File description:
** AObject.cpp
*/

#include "AObject.hpp"

AObject::AObject(char c, irr::core::vector3df(float, float, float) newPos)
{
    setType(c);
    _pos = newPos;
}

AObject::ObjectType AObject::getType(void) const
{
    return (_type);
}

AObject::ObjectType AObject::setType(char c)
{
    if (c == 0)
        _type = Wall;
    if (c == 1)
        _type = Floor;
    if (c == 2)
        _type = Obstacle;
}

irr::core::vector3df(float, float, float) AObject::getPos(void) const
{
    return (_pos);
}