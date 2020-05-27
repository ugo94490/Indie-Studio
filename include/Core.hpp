/*
** EPITECH PROJECT, 2020
** Core.hpp
** File description:
** Core.hpp
*/

#pragma once

#include <vector>
#include <irrlicht.h>
#include <Exception.hpp>

class Core
{
    public:
        Core();
        ~Core();
        void loop();
    private:
        irr::IrrlichtDevice *device;
        irr::video::IVideoDriver* driver;
        irr::scene::ISceneManager* smgr;
        irr::gui::IGUIEnvironment* guienv;
        irr::scene::IAnimatedMeshSceneNode* node;
};