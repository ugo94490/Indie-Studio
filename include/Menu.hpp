/*
** EPITECH PROJECT, 2020
** Menu.hpp
** File description:
** Menu.hpp
*/

#pragma once

#include "IModule.hpp"
#include "Event.hpp"
#include "Core.hpp"

class Menu : public IModule
{
    public:
        Menu(Core *obj);
        ~Menu();
        void Loop(std::vector<std::shared_ptr<IModule>> obj);
        void Button(std::shared_ptr<IModule> obj, irr::core::position2d<irr::s32>, std::vector<irr::core::rect<irr::s32>> rect);
        bool Button_bool(irr::core::position2d<irr::s32> pos, std::vector<irr::core::rect<irr::s32>> rect);
        void Game();
        void New_Game();
        void Load_Game();
    private:
        Core *core;
        irr::video::ITexture *images;
        irr::video::ITexture *button;
        std::vector<std::shared_ptr<IModule>> tab;
};
