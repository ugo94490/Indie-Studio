/*
** EPITECH PROJECT, 2020
** Settings.cpp
** File description:
** Settings.cpp
*/

#include <vector>
#include <chrono>
#include "Settings.hpp"
#include "Rect.hpp"
#include "Factory.hpp"

Settings::Settings(Core *obj)
{
    core = obj;
}

void Settings::Loop(std::vector<std::shared_ptr<IModule>> obj)
{
    tab = obj;
    while (core->device->run()) {
        core->driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        core->driver->draw2DImage(core->images, irr::core::position2d<irr::s32>(0,0));
        if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(760, 814), back_rect) == true)
            break;
        core->driver->endScene();
    }
}

Settings::~Settings()
{
}
