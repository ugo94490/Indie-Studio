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
	Event eve;

	event = eve;
    device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1920, 1080));
    if (!device)
        throw(Exception ("Error window not open"));
    device->setWindowCaption(L"Indie Studio");
    driver = device->getVideoDriver();
    smgr = device->getSceneManager();
    guienv = device->getGUIEnvironment();
    driver->getMaterial2D().TextureLayer[0].BilinearFilter=true;
    driver->getMaterial2D().AntiAliasing=video::EAAM_FULL_BASIC;
}

Core::~Core()
{
	device->drop();
}

void Core::launch()
{
    Game game(driver, smgr, device);
	//Menu obj(device, driver, smgr, guienv, event);
}