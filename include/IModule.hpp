/*
** EPITECH PROJECT, 2020
** IModule.hpp
** File description:
** IModule.hpp
*/

#pragma once

#include <irrlicht.h>
#include <vector>
#include <memory>
#include "APlayer.hpp"

class IModule
{
    public:
        virtual ~IModule() = default;
        virtual void Loop(std::vector<std::shared_ptr<IModule>> obj) = 0;
        std::vector<std::shared_ptr<APlayer>> character;
};
