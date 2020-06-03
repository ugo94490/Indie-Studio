/*
** EPITECH PROJECT, 2020
** Normal.hpp
** File description:
** Normal.hpp
*/

#pragma once

#include <string>
#include "Core.hpp"
#include "APlayer.hpp"

class Normal : public APlayer
{
    public:
        Normal(std::string str, irr::video::ITexture *bomberman);
        ~Normal();
    private:
        std::string name;
        irr::video::ITexture *skin;
};