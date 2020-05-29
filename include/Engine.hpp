/*
** EPITECH PROJECT, 2020
** Engine.hpp
** File description:
** Engine.hpp
*/

#pragma once

#include <irrlicht.h>

class Engine
{
    public:
        static irr::IrrlichtDevice *create_window();
        static int window_isOpen(irr::IrrlichtDevice *device);
        static void clear_screen(irr::video::IVideoDriver* driver);
        static void draw_scene(irr::scene::ISceneManager* smgr);
        static void draw_gui(irr::gui::IGUIEnvironment* guienv);
        static void display_screen(irr::video::IVideoDriver* driver);
        static void destroy_window(irr::IrrlichtDevice *device);
    private:
};
