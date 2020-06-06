/*
** EPITECH PROJECT, 2020
** Credit.cpp
** File description:
** Credit.cpp
*/

#include <vector>
#include <chrono>
#include "Credit.hpp"
#include "Rect.hpp"
#include "Factory.hpp"

Credit::Credit(Core *obj)
{
    core = obj;
}

void Credit::Loop(std::vector<std::shared_ptr<IModule>> obj)
{
    tab = obj;
    while (core->device->run()) {
        core->driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        core->driver->draw2DImage(core->other_back, irr::core::position2d<irr::s32>(0,0));
        core->driver->draw2DImage(core->xbox, irr::core::position2d<irr::s32>(630,290));
        core->font->draw(L"Game developed by Arthur Benard, Lucas Renard,\n Gregoire Brasseur, Paul Cochet and Ugo Levi", irr::core::rect<irr::s32>(400, 690, 1920, 750), irr::video::SColor(255,0,0,0));
        if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(760, 814), back_rect) == true)
            break;
        core->driver->endScene();
    }
}

Credit::~Credit()
{
}
