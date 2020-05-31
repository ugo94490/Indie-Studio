/*
** EPITECH PROJECT, 2020
** LeaderBoard.cpp
** File description:
** LeaderBoard.cpp
*/

#include <vector>
#include <fstream>
#include <iostream>
#include "LeaderBoard.hpp"
#include "Exception.hpp"
#include "Rect.hpp"

LeaderBoard::LeaderBoard(irr::IrrlichtDevice *dev, irr::video::IVideoDriver* dri, irr::scene::ISceneManager* scene, irr::gui::IGUIEnvironment* gui, Event *event)
{
    recv = event;
    device = dev;
    driver = dri;
    smgr = scene;
    guienv = gui;
    images = driver->getTexture("assets/Sprite/Menu.jpg");
    button = driver->getTexture("assets/Sprite/Button/INDIE.png");
    font = device->getGUIEnvironment()->getFont("assets/Font/FONT.png");
    if (font == 0)
        throw(Exception("Cant load font"));
}

void LeaderBoard::Button(std::shared_ptr<IModule> module, irr::core::position2d<irr::s32> pos, std::vector<irr::core::rect<irr::s32>> rect)
{
    int width = rect[2].getWidth();
    int height = rect[2].getHeight();

    if (recv->eve.MouseInput.X >= pos.X && recv->eve.MouseInput.X <= (pos.X + width) && recv->eve.MouseInput.Y >= pos.Y && recv->eve.MouseInput.Y <= (pos.Y + height) && recv->eve.MouseInput.isLeftPressed()) {
        driver->draw2DImage(button, pos, rect[2], 0, irr::video::SColor(255,255,255,255), true);
        module->Loop(tab);
    } else if (recv->eve.MouseInput.X >= pos.X && recv->eve.MouseInput.X <= (pos.X + width) && recv->eve.MouseInput.Y >= pos.Y && recv->eve.MouseInput.Y <= (pos.Y + height))
        driver->draw2DImage(button, pos, rect[1], 0, irr::video::SColor(255,255,255,255), true);
    else
        driver->draw2DImage(button, pos, rect[0], 0, irr::video::SColor(255,255,255,255), true);
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

    if (recv->eve.MouseInput.X >= pos.X && recv->eve.MouseInput.X <= (pos.X + width) && recv->eve.MouseInput.Y >= pos.Y && recv->eve.MouseInput.Y <= (pos.Y + height) && recv->eve.MouseInput.isLeftPressed()) {
        driver->draw2DImage(button, pos, rect[2], 0, irr::video::SColor(255,255,255,255), true);
        return (true);
    } else if (recv->eve.MouseInput.X >= pos.X && recv->eve.MouseInput.X <= (pos.X + width) && recv->eve.MouseInput.Y >= pos.Y && recv->eve.MouseInput.Y <= (pos.Y + height))
        driver->draw2DImage(button, pos, rect[1], 0, irr::video::SColor(255,255,255,255), true);
    else
        driver->draw2DImage(button, pos, rect[0], 0, irr::video::SColor(255,255,255,255), true);
    return (false);
}

void LeaderBoard::Loop(std::vector<std::shared_ptr<IModule>> obj)
{
    if (tab.empty() == true)
        tab = obj;
    getScore("assets/Score/score.txt");
    std::cout << "LOL" << std::endl;
    while (device->run()) {
        driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        driver->draw2DImage(images, irr::core::position2d<irr::s32>(0,0));
        if (Button_bool(irr::core::position2d<irr::s32>(480, 94), play_rect) == true)
            break;
        if (font) {
            for (size_t i = 0; i < score.size(); i++)
                font->draw(score[i].c_str(), irr::core::rect<irr::s32>(130, 50 * i, 300, 500), irr::video::SColor(255,0,0,0));
        }
        driver->endScene();
    }
}

LeaderBoard::~LeaderBoard()
{
}
