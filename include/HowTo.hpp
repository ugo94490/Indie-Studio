/*
** EPITECH PROJECT, 2020
** HowTo.hpp
** File description:
** HowTo.hpp
*/

#pragma once

#include "IModule.hpp"
#include "Event.hpp"
#include "Core.hpp"

class HowTo : public IModule
{
    public:
        HowTo(Core *obj);
        ~HowTo();
        void Loop(std::vector<std::shared_ptr<IModule>> obj);
        void Button(std::shared_ptr<IModule> obj, irr::core::position2d<irr::s32>, std::vector<irr::core::rect<irr::s32>> rect);
        bool Button_bool(irr::core::position2d<irr::s32> pos, std::vector<irr::core::rect<irr::s32>> rect);
    private:
        Core *core;
        irr::video::ITexture *images;
        irr::video::ITexture *button;
        std::vector<std::shared_ptr<IModule>> tab;
};
