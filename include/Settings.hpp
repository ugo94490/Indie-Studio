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
    private:
        Core *core;
        std::vector<std::shared_ptr<IModule>> tab;
};
