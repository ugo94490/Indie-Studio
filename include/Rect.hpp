/*
** EPITECH PROJECT, 2020
** Rect.hpp
** File description:
** Rect.hpp
*/

#pragma once

#include <irrlicht.h>
#include <vector>

std::vector<irr::core::rect<irr::s32>> play =
{
    irr::core::rect<irr::s32>(0, 0, 400, 173),
    irr::core::rect<irr::s32>(445, 0, 845, 173),
    irr::core::rect<irr::s32>(890, 0, 1290, 173)
};

std::vector<irr::core::rect<irr::s32>> quit =
{
    irr::core::rect<irr::s32>(0, 174, 400, 347),
    irr::core::rect<irr::s32>(445, 174, 845, 347),
    irr::core::rect<irr::s32>(890, 174, 1290, 347)
};

std::vector<irr::core::rect<irr::s32>> options =
{
    irr::core::rect<irr::s32>(0, 348, 400, 521),
    irr::core::rect<irr::s32>(445, 348, 845, 521),
    irr::core::rect<irr::s32>(890, 348, 1290, 521)
};

std::vector<irr::core::rect<irr::s32>> credit =
{
    irr::core::rect<irr::s32>(0, 522, 400, 695),
    irr::core::rect<irr::s32>(445, 522, 845, 695),
    irr::core::rect<irr::s32>(890, 522, 1290, 695)
};

std::vector<irr::core::rect<irr::s32>> score =
{
    irr::core::rect<irr::s32>(0, 696, 400, 869),
    irr::core::rect<irr::s32>(445, 696, 845, 869),
    irr::core::rect<irr::s32>(890, 696, 1290, 869)
};

std::vector<irr::core::rect<irr::s32>> rules =
{
    irr::core::rect<irr::s32>(0, 870, 400, 1043),
    irr::core::rect<irr::s32>(445, 870, 845, 1043),
    irr::core::rect<irr::s32>(890, 870, 1290, 1043)
};