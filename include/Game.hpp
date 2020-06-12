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
#include "Load.hpp"
#include "Save.hpp"

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
        bool check_end();
        void draw_time(float time);
        void end();
        void initLoop(std::vector<std::shared_ptr<IModule>> obj);
        std::pair<std::string, int> getPlayerScore();
        std::vector<std::pair<std::string, int>> getScore(std::string path);
        std::vector<std::pair<std::string, int>> concat_score(std::vector<std::pair<std::string, int>> tab_score, std::pair<std::string, int> score);
        void write_score(std::string path, std::vector<std::pair<std::string, int>> tab_score);
        void saveGame(std::string const &filepath);
        void loadGame(std::string const &filepath);
    private:
        std::vector<std::shared_ptr<IModule>> tab;
        std::list<std::shared_ptr<Player>> _players;
        std::list<std::shared_ptr<GameObject>> _objects;
        Core *core;
};
