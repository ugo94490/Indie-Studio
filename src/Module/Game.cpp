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
    core->driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, false);
    scene::ISceneNode *skybox = core->smgr->addSkyBoxSceneNode(
        core->driver->getTexture("./assets/textures/skybox/browncloud_up.jpg"),
        core->driver->getTexture("./assets/textures/skybox/browncloud_dn.jpg"),
        core->driver->getTexture("./assets/textures/skybox/browncloud_rt.jpg"),
        core->driver->getTexture("./assets/textures/skybox/browncloud_lf.jpg"),
        core->driver->getTexture("./assets/textures/skybox/browncloud_ft.jpg"),
        core->driver->getTexture("./assets/textures/skybox/browncloud_bk.jpg"));
    core->driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, true);
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