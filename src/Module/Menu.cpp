/*
** EPITECH PROJECT, 2020
** Menu.cpp
** File description:
** Menu.cpp
*/

#include <irrlicht.h>
#include <vector>
#include "Menu.hpp"

Menu::Menu(irr::IrrlichtDevice *dev, irr::video::IVideoDriver* dri, irr::scene::ISceneManager* scene, irr::gui::IGUIEnvironment* gui)
{
    device = dev;
    driver = dri;
    smgr = scene;
    guienv = gui;
    images = driver->getTexture("assets/Sprite/Menu.jpg");
    button = driver->getTexture("assets/Sprite/Button/Button.png");
    Loop();
}

void Menu::Button(IModule &module, irr::core::position2d<irr::s32> pos, std::vector<irr::core::rect<irr::s32>> rect)
{
    int width = rect[2].getWidth();
    int height = rect[2].getHeight();

    if (recv.eve.MouseInput.X >= pos.X && recv.eve.MouseInput.X <= (pos.X + width) && recv.eve.MouseInput.Y >= pos.Y && recv.eve.MouseInput.Y <= (pos.Y + height) && recv.eve.MouseInput.isLeftPressed()) {
        driver->draw2DImage(button, pos, rect[2], 0, irr::video::SColor(255,255,255,255), true);
        module.Loop();
    } else if (recv.eve.MouseInput.X >= pos.X && recv.eve.MouseInput.X <= (pos.X + width) && recv.eve.MouseInput.Y >= pos.Y && recv.eve.MouseInput.Y <= (pos.Y + height))
        driver->draw2DImage(button, pos, rect[1], 0, irr::video::SColor(255,255,255,255), true);
    else
        driver->draw2DImage(button, pos, rect[0], 0, irr::video::SColor(255,255,255,255), true);
}

void Menu::Loop()
{
    std::vector<irr::core::rect<irr::s32>> rect;
    rect.push_back(irr::core::rect<irr::s32>(300, 285, 700, 458));
    rect.push_back(irr::core::rect<irr::s32>(745, 285, 1145, 458));
    rect.push_back(irr::core::rect<irr::s32>(1190, 285, 1590, 458));

    device->setEventReceiver(&recv);
    while (device->run()) {
        driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        driver->draw2DImage(images, irr::core::position2d<irr::s32>(0,0));
        Button(game, irr::core::position2d<irr::s32>(280, 94), rect);
        Button(game, irr::core::position2d<irr::s32>(1240, 94), rect);
        Button(game, irr::core::position2d<irr::s32>(280, 454), rect);
        Button(game, irr::core::position2d<irr::s32>(1240, 454), rect);
        Button(game, irr::core::position2d<irr::s32>(280, 814), rect);
        Button(game, irr::core::position2d<irr::s32>(1240, 814), rect);
        driver->endScene();
    }
}

Menu::~Menu()
{
}
