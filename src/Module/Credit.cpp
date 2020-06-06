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

Credit::Credit(Core *obj)
{
    core = obj;
}

bool Credit::Button_bool(irr::core::position2d<irr::s32> pos, std::vector<irr::core::rect<irr::s32>> rect)
{
    int width = rect[2].getWidth();
    int height = rect[2].getHeight();
    static bool click = false;
    static std::chrono::steady_clock::time_point _start = std::chrono::steady_clock::now();
    static std::chrono::steady_clock::time_point _end = std::chrono::steady_clock::now();

    _end = std::chrono::steady_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count() > 500) {
        _start = std::chrono::steady_clock::now();
        click = false;
    }
    if (click == false && core->recv->eve.MouseInput.X >= pos.X && core->recv->eve.MouseInput.X <= (pos.X + width) && core->recv->eve.MouseInput.Y >= pos.Y && core->recv->eve.MouseInput.Y <= (pos.Y + height) && core->recv->eve.MouseInput.isLeftPressed()) {
        click = true;
        core->driver->draw2DImage(core->button, pos, rect[2], 0, irr::video::SColor(255,255,255,255), true);
        return (true);
    } else if (core->recv->eve.MouseInput.X >= pos.X && core->recv->eve.MouseInput.X <= (pos.X + width) && core->recv->eve.MouseInput.Y >= pos.Y && core->recv->eve.MouseInput.Y <= (pos.Y + height))
        core->driver->draw2DImage(core->button, pos, rect[1], 0, irr::video::SColor(255,255,255,255), true);
    else
        core->driver->draw2DImage(core->button, pos, rect[0], 0, irr::video::SColor(255,255,255,255), true);
    return (false);
}

void Credit::Button(std::shared_ptr<IModule> module, irr::core::position2d<irr::s32> pos, std::vector<irr::core::rect<irr::s32>> rect)
{
    int width = rect[2].getWidth();
    int height = rect[2].getHeight();

    if (core->recv->eve.MouseInput.X >= pos.X && core->recv->eve.MouseInput.X <= (pos.X + width) && core->recv->eve.MouseInput.Y >= pos.Y && core->recv->eve.MouseInput.Y <= (pos.Y + height) && core->recv->eve.MouseInput.isLeftPressed()) {
        core->driver->draw2DImage(core->button, pos, rect[2], 0, irr::video::SColor(255,255,255,255), true);
        module->Loop(tab);
    } else if (core->recv->eve.MouseInput.X >= pos.X && core->recv->eve.MouseInput.X <= (pos.X + width) && core->recv->eve.MouseInput.Y >= pos.Y && core->recv->eve.MouseInput.Y <= (pos.Y + height))
        core->driver->draw2DImage(core->button, pos, rect[1], 0, irr::video::SColor(255,255,255,255), true);
    else
        core->driver->draw2DImage(core->button, pos, rect[0], 0, irr::video::SColor(255,255,255,255), true);
}

void Credit::Loop(std::vector<std::shared_ptr<IModule>> obj)
{
    tab = obj;
    while (core->device->run()) {
        core->driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        core->driver->draw2DImage(core->images, irr::core::position2d<irr::s32>(0,0));
        core->driver->draw2DImage(core->xbox, irr::core::position2d<irr::s32>(630,290));
        core->font->draw(L"Game developed by Arthur Benard, Lucas Renard,\n Gregoire Brasseur, Paul Cochet and Ugo Levi", irr::core::rect<irr::s32>(400, 690, 1920, 750), irr::video::SColor(255,0,0,0));
        if (Button_bool(irr::core::position2d<irr::s32>(760, 814), back_rect) == true)
            break;
        core->driver->endScene();
    }
}

Credit::~Credit()
{
}
