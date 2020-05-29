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
}

Core::~Core()
{
	device->drop();
}

void Core::launch()
{
    //Game game;
	Menu obj(device, driver, smgr, guienv);
}