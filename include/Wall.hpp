/*
** EPITECH PROJECT, 2020
** Wall.hpp
** File description:
** Wall.hpp
*/

#pragma once
#include "AObject.hpp"

class Wall : public AObject
{
    public:
        Wall(float posx, float posy, scene::ISceneManager* smgr, video::IVideoDriver* driver);
        ~Wall();
};