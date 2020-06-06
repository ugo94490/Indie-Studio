/*
** EPITECH PROJECT, 2020
** Settings.hpp
** File description:
** Settings.hpp
*/

#pragma once

#include "IModule.hpp"
#include "Event.hpp"
#include "Core.hpp"

class Settings : public IModule
{
    public:
        Settings(Core *obj);
        ~Settings();
        void Loop(std::vector<std::shared_ptr<IModule>> obj);
        void Button(std::shared_ptr<IModule> obj, irr::core::position2d<irr::s32>, std::vector<irr::core::rect<irr::s32>> rect);
        bool Button_bool(irr::core::position2d<irr::s32> pos, std::vector<irr::core::rect<irr::s32>> rect);
    private:
        Core *core;
        std::vector<std::shared_ptr<IModule>> tab;
};
