/*
** EPITECH PROJECT, 2020
** Credit.cpp
** File description:
** Credit.cpp
*/

#include <vector>
#include "Credit.hpp"

Credit::Credit(irr::IrrlichtDevice *dev, irr::video::IVideoDriver* dri, irr::scene::ISceneManager* scene, irr::gui::IGUIEnvironment* gui, Event *event)
{
    recv = event;
    device = dev;
    driver = dri;
    smgr = scene;
    guienv = gui;
    images = driver->getTexture("assets/Sprite/Menu.jpg");
    button = driver->getTexture("assets/Sprite/Button/INDIE.png");
}

void Credit::Button(std::shared_ptr<IModule> module, irr::core::position2d<irr::s32> pos, std::vector<irr::core::rect<irr::s32>> rect)
{
    int width = rect[2].getWidth();
    int height = rect[2].getHeight();

    if (recv->eve.MouseInput.X >= pos.X && recv->eve.MouseInput.X <= (pos.X + width) && recv->eve.MouseInput.Y >= pos.Y && recv->eve.MouseInput.Y <= (pos.Y + height) && recv->eve.MouseInput.isLeftPressed()) {
        driver->draw2DImage(button, pos, rect[2], 0, irr::video::SColor(255,255,255,255), true);
        module->Loop(tab);
    } else if (recv->eve.MouseInput.X >= pos.X && recv->eve.MouseInput.X <= (pos.X + width) && recv->eve.MouseInput.Y >= pos.Y && recv->eve.MouseInput.Y <= (pos.Y + height))
        driver->draw2DImage(button, pos, rect[1], 0, irr::video::SColor(255,255,255,255), true);
    else
        driver->draw2DImage(button, pos, rect[0], 0, irr::video::SColor(255,255,255,255), true);
}

void Credit::Loop(std::vector<std::shared_ptr<IModule>> obj)
{
    tab = obj;
    while (device->run()) {
        driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        driver->draw2DImage(images, irr::core::position2d<irr::s32>(0,0));
        driver->endScene();
    }
}

Credit::~Credit()
{
}
