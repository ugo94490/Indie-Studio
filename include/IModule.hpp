/*
** EPITECH PROJECT, 2020
** IModule.hpp
** File description:
** IModule.hpp
*/

#pragma once

class IModule
{
    public:
        virtual ~IModule() = default;
        virtual void Loop() = 0;
    private:
};
