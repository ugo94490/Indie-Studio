/*
** EPITECH PROJECT, 2020
** Menu.hpp
** File description:
** Menu.hpp
*/

#pragma once

#include "IModule.hpp"
#include "Event.hpp"

class Menu : public IModule
{
    public:
        Menu(irr::IrrlichtDevice *device, irr::video::IVideoDriver* driver, irr::scene::ISceneManager* smgr, irr::gui::IGUIEnvironment* guienv);
        ~Menu();
    private:
        irr::IrrlichtDevice *device;
        irr::video::IVideoDriver* driver;
        irr::scene::ISceneManager* smgr;
        irr::gui::IGUIEnvironment* guienv;
};
