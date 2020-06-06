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
#include "HowTo.hpp"
#include "Credit.hpp"
#include "LeaderBoard.hpp"
#include "Settings.hpp"

Core::Core()
{
    std::shared_ptr<IModule> ptr;
    device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1920, 1080));
    if (!device)
        throw(Exception ("Error window not open"));
    device->setWindowCaption(L"Indie Studio");
    driver = device->getVideoDriver();
    smgr = device->getSceneManager();
    guienv = device->getGUIEnvironment();
    recv = new Event();
    device->setEventReceiver(recv);
    obj.push_back(ptr = std::make_shared<Menu>(this));
    obj.push_back(ptr = std::make_shared<Game>(this));
    obj.push_back(ptr = std::make_shared<LeaderBoard>(this));
    obj.push_back(ptr = std::make_shared<Settings>(this));
    obj.push_back(ptr = std::make_shared<HowTo>(this));
    obj.push_back(ptr = std::make_shared<Credit>(this));
    font = device->getGUIEnvironment()->getFont("assets/Font/FONT.png");
    if (font == 0)
        throw(Exception("Cant load font"));
    images = driver->getTexture("assets/Sprite/Menu.jpg");
    button = driver->getTexture("assets/Sprite/Button/INDIE.png");
    title = driver->getTexture("assets/Sprite/title.png");
    xbox = driver->getTexture("assets/Sprite/xbox.jpg");
}

Core::~Core()
{
    delete recv;
	device->drop();
}

void Core::launch()
{
    obj[0]->Loop(obj);
}