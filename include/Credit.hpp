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
    private:
        Core *core;
        std::vector<std::shared_ptr<IModule>> tab;
};
