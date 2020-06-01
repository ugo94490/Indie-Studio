/*
** EPITECH PROJECT, 2020
** Game.cpp
** File description:
** Game.cpp
*/

#include "Game.hpp"

Game::Game(Core *obj)
{
    core = obj;
}

void Game::Loop(std::vector<std::shared_ptr<IModule>> obj)
{
    tab = obj;
}

Game::~Game()
{
}