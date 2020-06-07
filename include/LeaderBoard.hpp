/*
** EPITECH PROJECT, 2020
** LeaderBoard.hpp
** File description:
** LeaderBoard.hpp
*/

#pragma once

#include "IModule.hpp"
#include "Event.hpp"
#include "Core.hpp"

class LeaderBoard : public IModule
{
    public:
        LeaderBoard(Core *obj);
        ~LeaderBoard();
        void Loop(std::vector<std::shared_ptr<IModule>> obj);
        void getScore(std::string path);
    private:
        Core *core;
        std::vector<std::shared_ptr<IModule>> tab;
        std::vector<std::string> score;
};
