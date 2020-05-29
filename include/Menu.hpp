/*
** EPITECH PROJECT, 2020
** Menu.hpp
** File description:
** Menu.hpp
*/

#pragma once

#include "IModule.hpp"
#include "Event.hpp"
#include "Game.hpp"
#include "IModule.hpp"

class Menu : public IModule
{
    public:
        Menu(irr::IrrlichtDevice *device, irr::video::IVideoDriver* driver, irr::scene::ISceneManager* smgr, irr::gui::IGUIEnvironment* guienv);
        ~Menu();
        void Loop();
        void Button(IModule &module, irr::core::position2d<irr::s32>, std::vector<irr::core::rect<irr::s32>> rect);
    private:
        irr::IrrlichtDevice *device;
        irr::video::IVideoDriver* driver;
        irr::scene::ISceneManager* smgr;
        irr::gui::IGUIEnvironment* guienv;
        irr::video::ITexture *images;
        irr::video::ITexture *button;
        Event recv;
        Game game;
};
