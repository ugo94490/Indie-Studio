/*
** EPITECH PROJECT, 2020
** Menu.cpp
** File description:
** Menu.cpp
*/

#include <vector>
#include <iostream>
#include <chrono>
#include "Menu.hpp"
#include "Rect.hpp"

Menu::Menu(Core *obj)
{
    core = obj;
    images = core->driver->getTexture("assets/Sprite/Menu.jpg");
    button = core->driver->getTexture("assets/Sprite/Button/INDIE.png");
    other = core->driver->getTexture("assets/Sprite/Button/Button.png");
}

void Menu::Button(std::shared_ptr<IModule> module, irr::core::position2d<irr::s32> pos, std::vector<irr::core::rect<irr::s32>> rect)
{
    int width = rect[2].getWidth();
    int height = rect[2].getHeight();

    if (core->recv->eve.MouseInput.X >= pos.X && core->recv->eve.MouseInput.X <= (pos.X + width) && core->recv->eve.MouseInput.Y >= pos.Y && core->recv->eve.MouseInput.Y <= (pos.Y + height) && core->recv->eve.MouseInput.isLeftPressed()) {
        core->driver->draw2DImage(button, pos, rect[2], 0, irr::video::SColor(255,255,255,255), true);
        module->Loop(tab);
    } else if (core->recv->eve.MouseInput.X >= pos.X && core->recv->eve.MouseInput.X <= (pos.X + width) && core->recv->eve.MouseInput.Y >= pos.Y && core->recv->eve.MouseInput.Y <= (pos.Y + height))
        core->driver->draw2DImage(button, pos, rect[1], 0, irr::video::SColor(255,255,255,255), true);
    else
        core->driver->draw2DImage(button, pos, rect[0], 0, irr::video::SColor(255,255,255,255), true);
}

bool Menu::Button_bool(irr::core::position2d<irr::s32> pos, std::vector<irr::core::rect<irr::s32>> rect)
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
        core->driver->draw2DImage(button, pos, rect[2], 0, irr::video::SColor(255,255,255,255), true);
        return (true);
    } else if (core->recv->eve.MouseInput.X >= pos.X && core->recv->eve.MouseInput.X <= (pos.X + width) && core->recv->eve.MouseInput.Y >= pos.Y && core->recv->eve.MouseInput.Y <= (pos.Y + height))
        core->driver->draw2DImage(button, pos, rect[1], 0, irr::video::SColor(255,255,255,255), true);
    else
        core->driver->draw2DImage(button, pos, rect[0], 0, irr::video::SColor(255,255,255,255), true);
    return (false);
}

void Menu::Loop(std::vector<std::shared_ptr<IModule>> obj)
{
    if (tab.empty() == true)
        tab = obj;
    while (core->device->run()) {
        core->driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        core->driver->draw2DImage(images, irr::core::position2d<irr::s32>(0,0));
        if (Button_bool(irr::core::position2d<irr::s32>(280, 94), play_rect) == true)
            Game();
        Button(tab[2], irr::core::position2d<irr::s32>(1240, 94), score_rect);
        Button(tab[3], irr::core::position2d<irr::s32>(280, 454), options_rect);
        Button(tab[4], irr::core::position2d<irr::s32>(1240, 454), rules_rect);
        Button(tab[5], irr::core::position2d<irr::s32>(280, 814), credit_rect);
        if (Button_bool(irr::core::position2d<irr::s32>(1240, 814), quit_rect) == true)
            break;
        core->driver->endScene();
    }
}

void Menu::Game()
{
    while (core->device->run()) {
        core->driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        core->driver->draw2DImage(images, irr::core::position2d<irr::s32>(0,0));
        if (Button_bool(irr::core::position2d<irr::s32>(280, 454), new_rect) == true)
            New_Game(4);
        if (Button_bool(irr::core::position2d<irr::s32>(1240, 454), load_rect) == true)
            Load_Game();
        if (Button_bool(irr::core::position2d<irr::s32>(760, 814), back_rect) == true)
            break;
        core->driver->endScene();
    }
}

void Menu::New_Game(int nb)
{
    int p1 = 0;
    int p2 = -1;
    int p3 = -1;
    int p4 = -1;

    if (nb >= 2)
        p2 = 0;
    if (nb >= 3)
        p3 = 0;
    if (nb >= 4)
        p4 = 0;
    while (core->device->run()) {
        core->driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        core->driver->draw2DImage(images, irr::core::position2d<irr::s32>(0,0));
        if (Button_bool(irr::core::position2d<irr::s32>(760, 814), back_rect) == true)
            break;
        if (Button_bool(irr::core::position2d<irr::s32>(64, 280), rectangle_rect) == true && nb >= 1)
            p1 >= 4 ? p1 = 0 : p1++;
        if (Button_bool(irr::core::position2d<irr::s32>(528, 280), rectangle_rect) == true && nb >= 2)
            p2 >= 4 ? p2 = 0 : p2++;
        if (Button_bool(irr::core::position2d<irr::s32>(992, 280), rectangle_rect) == true && nb >= 3)
            p3 >= 4 ? p3 = 0 : p3++;
        if (Button_bool(irr::core::position2d<irr::s32>(1456, 280), rectangle_rect) == true && nb >= 4)
            p4 >= 4 ? p4 = 0 : p4++;
        core->driver->endScene();
       // std::cout << "P1:" << p1 << " P2:" << p2 << " P3:" << p3 << " P4:" << p4 << std::endl;
        //std::cout << core->device->getTimer()->getTime() << std::endl;
    }
    //tab[1]->Loop(tab);
}

void Menu::Load_Game()
{
    tab[1]->Loop(tab);
}

Menu::~Menu()
{
}
