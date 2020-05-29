/*
** EPITECH PROJECT, 2020
** Game.hpp
** File description:
** Game.hpp
*/

#pragma once

#include "IModule.hpp"
#include <iostream>

class Game : public IModule
{
    public:
        Game(irr::IrrlichtDevice *dev, irr::video::IVideoDriver* dri, irr::scene::ISceneManager* sm, irr::gui::IGUIEnvironment* gui);
        void Loop(std::vector<std::shared_ptr<IModule>> obj);
        ~Game();
    private:
    irr::IrrlichtDevice *device;
    irr::video::IVideoDriver* driver;
    irr::scene::ISceneManager* smgr;
    irr::gui::IGUIEnvironment* guienv;
    std::vector<std::shared_ptr<IModule>> tab;
};
