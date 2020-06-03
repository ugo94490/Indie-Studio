/*
** EPITECH PROJECT, 2020
** Game.cpp
** File description:
** Game.cpp
*/

#include "Game.hpp"

Game::Game(Core *obj)
{
    core = obj;
}

void Game::Loop(std::vector<std::shared_ptr<IModule>> obj)
{
    tab = obj;
    Map mapBomber(core->smgr, core->driver);
    core->driver->getMaterial2D().TextureLayer[0].BilinearFilter=true;
    core->driver->getMaterial2D().AntiAliasing=video::EAAM_FULL_BASIC;
    core->smgr->addCameraSceneNode(0, irr::core::vector3df(-20,250,-20), irr::core::vector3df(104,0,136));
    while(core->device->run() && core->driver)
    {
        if (core->device->isWindowActive())
        {
            core->driver->beginScene(true, true, video::SColor(0,0,0,0));
            core->smgr->drawAll();
            core->driver->endScene();
        }
    }
}

Game::~Game()
{
}