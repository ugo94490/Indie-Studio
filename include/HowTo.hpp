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
    private:
        Core *core;
        std::vector<std::shared_ptr<IModule>> tab;
};
