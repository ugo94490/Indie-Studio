/*
** EPITECH PROJECT, 2020
** Core.hpp
** File description:
** Core.hpp
*/

#pragma once

#include <irrlicht.h>
#include <Exception.hpp>
#include "Event.hpp"
#include "IModule.hpp"

class Core
{
    public:
        Core();
        ~Core();
        void launch();
        irr::IrrlichtDevice *device;
        irr::video::IVideoDriver* driver;
        irr::scene::ISceneManager* smgr;
        irr::gui::IGUIEnvironment* guienv;
        irr::scene::IAnimatedMeshSceneNode* node;
        std::vector<std::shared_ptr<IModule>> obj;
        irr::gui::IGUIFont *font;
        Event *recv;
        irr::video::ITexture *images;
        irr::video::ITexture *button;
        irr::video::ITexture *title;
        irr::video::ITexture *xbox;
};