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

LeaderBoard::LeaderBoard(Core *obj)
{
    core = obj;
    images = core->driver->getTexture("assets/Sprite/Menu.jpg");
    button = core->driver->getTexture("assets/Sprite/Button/INDIE.png");
}

void LeaderBoard::Button(std::shared_ptr<IModule> module, irr::core::position2d<irr::s32> pos, std::vector<irr::core::rect<irr::s32>> rect)
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

bool LeaderBoard::Button_bool(irr::core::position2d<irr::s32> pos, std::vector<irr::core::rect<irr::s32>> rect)
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

void LeaderBoard::Loop(std::vector<std::shared_ptr<IModule>> obj)
{
    if (tab.empty() == true)
        tab = obj;
    getScore("assets/Score/score.txt");
    while (core->device->run()) {
        core->driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        core->driver->draw2DImage(images, irr::core::position2d<irr::s32>(0,0));
        if (Button_bool(irr::core::position2d<irr::s32>(760, 814), back_rect) == true)
            break;
        Button_bool(irr::core::position2d<irr::s32>(760, 280), rectangle_rect);
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