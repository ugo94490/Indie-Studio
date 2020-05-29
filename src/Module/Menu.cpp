/*
** EPITECH PROJECT, 2020
** Menu.cpp
** File description:
** Menu.cpp
*/

#include <irrlicht.h>
#include "Menu.hpp"
#include "Event.hpp"

Menu::Menu(irr::IrrlichtDevice *dev, irr::video::IVideoDriver* dri, irr::scene::ISceneManager* scene, irr::gui::IGUIEnvironment* gui)
{
    Event recv;
    device = dev;
    driver = dri;
    smgr = scene;
    guienv = gui;
    device->setEventReceiver(&recv);
    irr::video::ITexture *images = driver->getTexture("assets/Sprite/Menu.jpg");
    irr::video::ITexture *button = driver->getTexture("assets/Sprite/Button/Button.png");
    while (device->run()) {
        driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        driver->draw2DImage(images, irr::core::position2d<irr::s32>(0,0));
        if (recv.eve.MouseInput.X >= 0 && recv.eve.MouseInput.X <= 398 && recv.eve.MouseInput.Y >= 0 && recv.eve.MouseInput.Y <= 172)
            driver->draw2DImage(button, irr::core::position2d<irr::s32>(0,0), irr::core::rect<irr::s32>(744, 82, 1144, 254), 0, irr::video::SColor(255,255,255,255), true);
        else
            driver->draw2DImage(button, irr::core::position2d<irr::s32>(0,0), irr::core::rect<irr::s32>(301, 82, 699, 254), 0, irr::video::SColor(255,255,255,255), true);
        driver->endScene();
    }
}

Menu::~Menu()
{
}
