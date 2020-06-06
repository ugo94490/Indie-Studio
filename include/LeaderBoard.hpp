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
        void Button(std::shared_ptr<IModule> obj, irr::core::position2d<irr::s32>, std::vector<irr::core::rect<irr::s32>> rect);
        bool Button_bool(irr::core::position2d<irr::s32> pos, std::vector<irr::core::rect<irr::s32>> rect);
        void getScore(std::string path);
    private:
        Core *core;
        std::vector<std::shared_ptr<IModule>> tab;
        std::vector<std::string> score;
};
