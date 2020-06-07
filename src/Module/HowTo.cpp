/*
** EPITECH PROJECT, 2020
** HowTo.cpp
** File description:
** HowTo.cpp
*/

#include <vector>
#include <chrono>
#include "HowTo.hpp"
#include "Rect.hpp"
#include "Factory.hpp"

HowTo::HowTo(Core *obj)
{
    core = obj;
}

void HowTo::Loop(std::vector<std::shared_ptr<IModule>> obj)
{
    tab = obj;
    while (core->device->run()) {
        core->driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        core->driver->draw2DImage(core->other_back, irr::core::position2d<irr::s32>(0,0));
        if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(760, 814), back_rect) == true)
            break;
        core->font->draw(L"Incarne un poseur de bombes, le but étant de faire\n   exploser les adversaires/ennemis pour gagner.", irr::core::rect<irr::s32>(400, 690, 1920, 750), irr::video::SColor(255,0,0,0));
        core->driver->endScene();
    }
}

HowTo::~HowTo()
{
}
