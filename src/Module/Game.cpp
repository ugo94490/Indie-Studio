/*
** EPITECH PROJECT, 2020
** Game.cpp
** File description:
** Game.cpp
*/

#include "Game.hpp"

Game::Game(video::IVideoDriver* driver, irr::scene::ISceneManager* smgr, irr::IrrlichtDevice *device)
{
    core(driver, smgr, device);
}

void Game::core(video::IVideoDriver* driver, irr::scene::ISceneManager* smgr, irr::IrrlichtDevice *device)
{
    GeneratorMap gene(17, 13);
    Map mapBomber(driver);
    while(device->run() && driver)
    {
        if (device->isWindowActive())
        {
            driver->beginScene(true, true, video::SColor(0,0,0,0));
            mapBomber.displayMap(driver);
            smgr->drawAll();
            driver->endScene();
        }
    }
}

Game::~Game()
{
}
