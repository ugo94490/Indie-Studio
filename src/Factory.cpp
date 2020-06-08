/*
** EPITECH PROJECT, 2020
** Factory.cpp
** File description:
** Factory.cpp
*/

#include <chrono>
#include "Factory.hpp"

void Factory::Button(Core *core, std::shared_ptr<IModule> module, irr::core::position2d<irr::s32> pos, std::vector<irr::core::rect<irr::s32>> rect)
{
    int width = rect[2].getWidth();
    int height = rect[2].getHeight();

    if (core->recv->eve.MouseInput.X >= pos.X && core->recv->eve.MouseInput.X <= (pos.X + width) && core->recv->eve.MouseInput.Y >= pos.Y && core->recv->eve.MouseInput.Y <= (pos.Y + height) && core->recv->eve.MouseInput.isLeftPressed()) {
        core->driver->draw2DImage(core->button, pos, rect[2], 0, irr::video::SColor(255,255,255,255), true);
        module->Loop(core->obj);
    } else if (core->recv->eve.MouseInput.X >= pos.X && core->recv->eve.MouseInput.X <= (pos.X + width) && core->recv->eve.MouseInput.Y >= pos.Y && core->recv->eve.MouseInput.Y <= (pos.Y + height))
        core->driver->draw2DImage(core->button, pos, rect[1], 0, irr::video::SColor(255,255,255,255), true);
    else
        core->driver->draw2DImage(core->button, pos, rect[0], 0, irr::video::SColor(255,255,255,255), true);
}

bool Factory::Button_bool(Core *core, irr::core::position2d<irr::s32> pos, std::vector<irr::core::rect<irr::s32>> rect)
{
    int width = rect[2].getWidth();
    int height = rect[2].getHeight();
    static bool click = false;
    static std::chrono::steady_clock::time_point _start = std::chrono::steady_clock::now();
    static std::chrono::steady_clock::time_point _end = std::chrono::steady_clock::now();

    _end = std::chrono::steady_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count() > 600) {
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

irr::video::ITexture *Factory::Check_load(irr::video::IVideoDriver *driver, std::string path)
{
    irr::video::ITexture *texture = driver->getTexture(path.c_str());
    if (driver == 0)
        throw (Exception("Can't Load texture"));
    return (texture);
}

irr::scene::IAnimatedMesh *Factory::Check_mesh(scene::ISceneManager* smgr, std::string path)
{
    irr::scene::IAnimatedMesh *mesh = smgr->getMesh(path.c_str());
    if (mesh == 0)
        throw (Exception("Can't Load Mesh"));
    return (mesh);
}