/*
** EPITECH PROJECT, 2020
** Game.hpp
** File description:
** Game.hpp
*/

#pragma once

#include <iostream>
#include "IModule.hpp"
#include "Event.hpp"
#include "Core.hpp"
#include "Map.hpp"
#include "APlayer.hpp"

class Game : public IModule
{
    public:
        Game(Core *obj);
        void Loop(std::vector<std::shared_ptr<IModule>> obj);
        ~Game();
    private:
    std::vector<std::shared_ptr<IModule>> tab;
    Core *core;
};
