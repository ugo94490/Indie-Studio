/*
** EPITECH PROJECT, 2020
** LeaderBoard.cpp
** File description:
** LeaderBoard.cpp
*/

#include <vector>
#include <fstream>
#include <iostream>
#include <chrono>
#include "LeaderBoard.hpp"
#include "Exception.hpp"
#include "Rect.hpp"
#include "Factory.hpp"

LeaderBoard::LeaderBoard(Core *obj)
{
    core = obj;
}

void LeaderBoard::getScore(std::string path)
{
    std::fstream myfile(path);
    std::string line;

    score.erase(score.begin(), score.end());
    if (!myfile.is_open())
        throw(Exception("Can't open file"));
    for (int i = 0; !myfile.eof(); i++) {
        getline (myfile, line);
        score.push_back(line);
    }
}

void LeaderBoard::Loop(std::vector<std::shared_ptr<IModule>> obj)
{
    if (tab.empty() == true)
        tab = obj;
    getScore("assets/Score/score.txt");
    while (core->device->run()) {
        core->driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        core->driver->draw2DImage(core->images, irr::core::position2d<irr::s32>(0,0));
        if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(760, 814), back_rect) == true)
            break;
        Factory::Button_bool(core, irr::core::position2d<irr::s32>(760, 280), rectangle_rect);
        if (core->font) {
            for (size_t i = 0; i < score.size(); i++)
                core->font->draw(score[i].c_str(), irr::core::rect<irr::s32>(960 - (score[i].size() * 24 / 2), 300 + (50 * i), 960 + score[i].size(), 650), irr::video::SColor(255,0,0,0));
        }
        core->driver->endScene();
    }
}

LeaderBoard::~LeaderBoard()
{
}
