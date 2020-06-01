/*
** EPITECH PROJECT, 2020
** AObject.cpp
** File description:
** AObject.cpp
*/

#include "AObject.hpp"

AObject::ObjectType AObject::getType(void) const
{
    return (_type);
}

irr::core::vector3d<f32> AObject::getPos(void) const
{
    return (_pos);
}