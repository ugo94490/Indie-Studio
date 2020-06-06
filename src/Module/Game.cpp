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

std::shared_ptr<Player> Game::getPlayerInput(char c)
{
    for (size_t i = 0; i < character.size(); i++)
        for (size_t j = 0; j < character[i]->_bind.size(); j++)
            if (character[i]->_bind[j].second == c)
                return (character[i]);
    return (nullptr);
}

void Game::Loop(std::vector<std::shared_ptr<IModule>> obj)
{
    tab = obj;
    core->driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, false);
    scene::ISceneNode *skybox = core->smgr->addSkyBoxSceneNode(
        core->driver->getTexture("./assets/textures/skybox/browncloud_up.jpg"),
        core->driver->getTexture("./assets/textures/skybox/browncloud_dn.jpg"),
        core->driver->getTexture("./assets/textures/skybox/browncloud_rt.jpg"),
        core->driver->getTexture("./assets/textures/skybox/browncloud_lf.jpg"),
        core->driver->getTexture("./assets/textures/skybox/browncloud_ft.jpg"),
        core->driver->getTexture("./assets/textures/skybox/browncloud_bk.jpg"));
    core->driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, true);
    Map mapBomber(core->smgr, core->driver);
    core->driver->getMaterial2D().TextureLayer[0].BilinearFilter=true;
    core->driver->getMaterial2D().AntiAliasing=video::EAAM_FULL_BASIC;
    core->smgr->addCameraSceneNode(0, irr::core::vector3df(340,400,-60), irr::core::vector3df(340,0,340));

    while(core->device->run() && core->driver) {
        if (core->device->isWindowActive()) {
            core->driver->beginScene(true, true, video::SColor(0,0,0,0));
            core->smgr->drawAll();
            core->driver->endScene();
        }
    }
}

Game::~Game()
{
}