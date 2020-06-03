/*
** EPITECH PROJECT, 2020
** Floor.hpp
** File description:
** Floor.hpp
*/

#pragma once
#include "AObject.hpp"

class Floor : public AObject
{
    public:
        Floor(float posx, float posy, scene::ISceneManager* smgr, video::IVideoDriver* driver);
        ~Floor();
};