/*
** EPITECH PROJECT, 2020
** Game.hpp
** File description:
** Game.hpp
*/

#pragma once

#include "IModule.hpp"
#include <iostream>

class Game : public IModule
{
    public:
        Game();
        void Loop();
        ~Game();
    private:
};
