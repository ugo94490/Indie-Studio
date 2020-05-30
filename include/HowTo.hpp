/*
** EPITECH PROJECT, 2020
** HowTo.hpp
** File description:
** HowTo.hpp
*/

#pragma once

#include "IModule.hpp"
#include "Event.hpp"

class HowTo : public IModule
{
    public:
        HowTo(irr::IrrlichtDevice *device, irr::video::IVideoDriver* driver, irr::scene::ISceneManager* smgr, irr::gui::IGUIEnvironment* guienv);
        ~HowTo();
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
