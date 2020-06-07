/*
** EPITECH PROJECT, 2020
** Credit.hpp
** File description:
** Credit.hpp
*/

#pragma once

#include "IModule.hpp"
#include "Event.hpp"
#include "Core.hpp"

class Credit : public IModule
{
    public:
        Credit(Core *obj);
        ~Credit();
        void Loop(std::vector<std::shared_ptr<IModule>> obj);
        void Button(std::shared_ptr<IModule> obj, irr::core::position2d<irr::s32>, std::vector<irr::core::rect<irr::s32>> rect);
        bool Button_bool(irr::core::position2d<irr::s32> pos, std::vector<irr::core::rect<irr::s32>> rect);
    private:
        Core *core;
        irr::video::ITexture *images;
        irr::video::ITexture *button;
        irr::video::ITexture *xbox;
        std::vector<std::shared_ptr<IModule>> tab;
};
