/*
** EPITECH PROJECT, 2020
** Factory.hpp
** File description:
** Factory.hpp
*/

#pragma once

#include <vector>
#include "IModule.hpp"
#include "Core.hpp"

class Factory
{
    public:
        static irr::scene::IAnimatedMesh *Check_mesh(scene::ISceneManager* smgr, std::string path);
        static irr::video::ITexture *Check_load(irr::video::IVideoDriver *driver, std::string path);
        static void Button(Core *core, std::shared_ptr<IModule> obj, irr::core::position2d<irr::s32>, std::vector<irr::core::rect<irr::s32>> rect);
        static bool Button_bool(Core *core, irr::core::position2d<irr::s32> pos, std::vector<irr::core::rect<irr::s32>> rect);
        static bool num(std::string str);
};