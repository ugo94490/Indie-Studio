/*
** EPITECH PROJECT, 2020
** Game.hpp
** File description:
** Game.hpp
*/

#pragma once

#include "IModule.hpp"
#include "Map.hpp"
#include "GeneratorMap.hpp"

class Game : public IModule
{
    public:
        Game(video::IVideoDriver* driver, irr::scene::ISceneManager* smgr, irr::IrrlichtDevice *device);
        void core(video::IVideoDriver* driver, irr::scene::ISceneManager* smgr, irr::IrrlichtDevice *device);
        ~Game();
    private:
};
