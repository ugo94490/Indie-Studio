/*
** EPITECH PROJECT, 2020
** AObject.cpp
** File description:
** AObject.cpp
*/

#include "AObject.hpp"

AObject::AObject(AObject::ObjectType)
{
}

AObject::ObjectType AObject::getType(void)
{
    return (type);
}

std::vector<float> AObject::getPos(void)
{
    return (pos);
}