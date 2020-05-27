/*
** EPITECH PROJECT, 2020
** AObject.cpp
** File description:
** AObject.cpp
*/

#include "AObject.hpp"

AObject::AObject(AObject::ObjectType, std::vector<float> newPos)
{
    type = AObject::ObjectType;
    pos = newPos;
}

AObject::ObjectType AObject::getType(void) const
{
    return (type);
}

std::vector<float> AObject::getPos(void) const
{
    return (pos);
}