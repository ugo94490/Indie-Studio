/*
** EPITECH PROJECT, 2020
** Core.cpp
** File description:
** Core.cpp
*/

#include "Core.hpp"
#include "Menu.hpp"
#include "Event.hpp"
#include "Game.hpp"

Core::Core()
{
    device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1920, 1080));
    if (!device)
        throw(Exception ("Error window not open"));
    device->setWindowCaption(L"Indie Studio");
    driver = device->getVideoDriver();
    smgr = device->getSceneManager();
    guienv = device->getGUIEnvironment();
    std::shared_ptr<IModule> menu (new Menu(device, driver, smgr, guienv));
    std::shared_ptr<IModule> game (new Game(device, driver, smgr, guienv));
    std::shared_ptr<IModule> leaderboard (new LeaderBoard(device, driver, smgr, guienv));
    std::shared_ptr<IModule> settings (new Settings(device, driver, smgr, guienv));
    obj.push_back(menu);
    obj.push_back(game);
    obj.push_back(leaderboard);
    obj.push_back(settings);
}

Core::~Core()
{
	device->drop();
}

void Core::launch()
{
    obj[0]->Loop(obj);
}