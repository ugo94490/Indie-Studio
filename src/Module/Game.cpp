/*
** EPITECH PROJECT, 2020
** Game.cpp
** File description:
** Game.cpp
*/

#include "Game.hpp"

Game::Game(irr::IrrlichtDevice *dev, irr::video::IVideoDriver* dri, irr::scene::ISceneManager* sm, irr::gui::IGUIEnvironment* gui, Event *event)
{
    recv = event;
    device = dev;
    driver = dri;
    smgr = sm;
    guienv = gui;
}

void Game::Loop(std::vector<std::shared_ptr<IModule>> obj)
{
    tab = obj;
}

Game::~Game()
{
}