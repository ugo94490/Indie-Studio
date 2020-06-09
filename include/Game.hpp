/*
** EPITECH PROJECT, 2020
** Game.hpp
** File description:
** Game.hpp
*/

#pragma once

#include <iostream>
#include <chrono>
#include "IModule.hpp"
#include "Event.hpp"
#include "Core.hpp"
#include "Map.hpp"
#include "Player.hpp"

class Game : public IModule
{
    public:
        Game(Core *obj);
        void Loop(std::vector<std::shared_ptr<IModule>> obj);
        ~Game();
        std::shared_ptr<Player> getPlayerInput(char c);
        void assignPlayerPos();
        void getInput();
        void removeDead();
        void Pause();
    private:
        std::vector<std::shared_ptr<IModule>> tab;
        std::list<std::shared_ptr<Player>> _players;
        std::list<std::shared_ptr<GameObject>> _objects;
        Core *core;
};
