/*
** EPITECH PROJECT, 2020
** Normal.cpp
** File description:
** Normal.cpp
*/

#include "Normal.hpp"

Normal::Normal(std::string str, irr::video::ITexture *bomberman)
{
    name = str;
    skin = bomberman;
}

Normal::~Normal()
{
}