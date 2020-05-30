/*
** EPITECH PROJECT, 2020
** Menu.cpp
** File description:
** Menu.cpp
*/

#include <vector>
#include "Menu.hpp"
#include "Rect.hpp"

Menu::Menu(irr::IrrlichtDevice *dev, irr::video::IVideoDriver* dri, irr::scene::ISceneManager* scene, irr::gui::IGUIEnvironment* gui)
{
    device = dev;
    driver = dri;
    smgr = scene;
    guienv = gui;
    images = driver->getTexture("assets/Sprite/Menu.jpg");
    button = driver->getTexture("assets/Sprite/Button/INDIE.png");
}

void Menu::Button(std::shared_ptr<IModule> module, irr::core::position2d<irr::s32> pos, std::vector<irr::core::rect<irr::s32>> rect)
{
    int width = rect[2].getWidth();
    int height = rect[2].getHeight();

    if (recv.eve.MouseInput.X >= pos.X && recv.eve.MouseInput.X <= (pos.X + width) && recv.eve.MouseInput.Y >= pos.Y && recv.eve.MouseInput.Y <= (pos.Y + height) && recv.eve.MouseInput.isLeftPressed()) {
        driver->draw2DImage(button, pos, rect[2], 0, irr::video::SColor(255,255,255,255), true);
        module->Loop(tab);
    } else if (recv.eve.MouseInput.X >= pos.X && recv.eve.MouseInput.X <= (pos.X + width) && recv.eve.MouseInput.Y >= pos.Y && recv.eve.MouseInput.Y <= (pos.Y + height))
        driver->draw2DImage(button, pos, rect[1], 0, irr::video::SColor(255,255,255,255), true);
    else
        driver->draw2DImage(button, pos, rect[0], 0, irr::video::SColor(255,255,255,255), true);
}

bool Menu::Button_bool(irr::core::position2d<irr::s32> pos, std::vector<irr::core::rect<irr::s32>> rect)
{
    int width = rect[2].getWidth();
    int height = rect[2].getHeight();

    if (recv.eve.MouseInput.X >= pos.X && recv.eve.MouseInput.X <= (pos.X + width) && recv.eve.MouseInput.Y >= pos.Y && recv.eve.MouseInput.Y <= (pos.Y + height) && recv.eve.MouseInput.isLeftPressed()) {
        driver->draw2DImage(button, pos, rect[2], 0, irr::video::SColor(255,255,255,255), true);
        return (true);
    } else if (recv.eve.MouseInput.X >= pos.X && recv.eve.MouseInput.X <= (pos.X + width) && recv.eve.MouseInput.Y >= pos.Y && recv.eve.MouseInput.Y <= (pos.Y + height))
        driver->draw2DImage(button, pos, rect[1], 0, irr::video::SColor(255,255,255,255), true);
    else
        driver->draw2DImage(button, pos, rect[0], 0, irr::video::SColor(255,255,255,255), true);
    return (false);
}

void Menu::Loop(std::vector<std::shared_ptr<IModule>> obj)
{
    tab = obj;
    device->setEventReceiver(&recv);
    while (device->run()) {
        driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        driver->draw2DImage(images, irr::core::position2d<irr::s32>(0,0));
        Button(obj[1], irr::core::position2d<irr::s32>(280, 94), play);
        Button(obj[2], irr::core::position2d<irr::s32>(1240, 94), score);
        Button(obj[3], irr::core::position2d<irr::s32>(280, 454), options);
        Button(obj[4], irr::core::position2d<irr::s32>(1240, 454), rules);
        Button(obj[5], irr::core::position2d<irr::s32>(280, 814), credit);
        if (Button_bool(irr::core::position2d<irr::s32>(1240, 814), quit) == true)
            break;
        driver->endScene();
    }
}

Menu::~Menu()
{
}
