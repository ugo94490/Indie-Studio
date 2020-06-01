/*
** EPITECH PROJECT, 2020
** Credit.hpp
** File description:
** Credit.hpp
*/

#pragma once

#include "IModule.hpp"
#include "Event.hpp"

class Credit : public IModule
{
    public:
        Credit(irr::IrrlichtDevice *device, irr::video::IVideoDriver* driver, irr::scene::ISceneManager* smgr, irr::gui::IGUIEnvironment* guienv);
        ~Credit();
        void Loop(std::vector<std::shared_ptr<IModule>> obj);
        void Button(std::shared_ptr<IModule> obj, irr::core::position2d<irr::s32>, std::vector<irr::core::rect<irr::s32>> rect);
    private:
        irr::IrrlichtDevice *device;
        irr::video::IVideoDriver* driver;
        irr::scene::ISceneManager* smgr;
        irr::gui::IGUIEnvironment* guienv;
        irr::video::ITexture *images;
        irr::video::ITexture *button;
        Event recv;
        std::vector<std::shared_ptr<IModule>> tab;
};
