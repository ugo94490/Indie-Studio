/*
** EPITECH PROJECT, 2020
** Obstacle.hpp
** File description:
** Obstacle.hpp
*/

#pragma once
#include "AObject.hpp"

class Obstacle : public AObject
{
    public:
        Obstacle(float posx, float posy, scene::ISceneManager* smgr, video::IVideoDriver* driver);
        ~Obstacle();
};