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

LeaderBoard::LeaderBoard(irr::IrrlichtDevice *dev, irr::video::IVideoDriver* dri, irr::scene::ISceneManager* scene, irr::gui::IGUIEnvironment* gui)
{
    device = dev;
    driver = dri;
    smgr = scene;
    guienv = gui;
    images = driver->getTexture("assets/Sprite/Menu.jpg");
    button = driver->getTexture("assets/Sprite/Button/INDIE.png");
    //font = device->getGUIEnvironment()->getBuiltInFont();
    font = device->getGUIEnvironment()->getFont("assets/Font/esp_ital.ttf");
    if (font == 0)
        throw(Exception("Cant load font"));
}

void LeaderBoard::Button(std::shared_ptr<IModule> module, irr::core::position2d<irr::s32> pos, std::vector<irr::core::rect<irr::s32>> rect)
{
    int width = rect[2].getWidth();
    int height = rect[2].getHeight();

    if (recv.eve.MouseInput.X >= pos.X && recv.eve.MouseInput.X <= (pos.X + width) && recv.eve.MouseInput.Y >= pos.Y && recv.eve.MouseInput.Y <= (pos.Y + height) && recv.eve.MouseInput.isLeftPressed()) {
        driver->draw2DImage(button, pos, rect[2], 0, irr::video::SColor(255,255,255,255), true);
        module->Loop(tab);
    } else if (recv.eve.MouseInput.X >= pos.X && recv.eve.MouseInput.X <= (pos.X + width) && recv.eve.MouseInput.Y >= pos.Y && recv.eve.MouseInput.Y <= (pos.Y + height))
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

void LeaderBoard::Loop(std::vector<std::shared_ptr<IModule>> obj)
{
    tab = obj;
    device->setEventReceiver(&recv);
    getScore("assets/Score/score.txt");
    while (device->run()) {
        driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        driver->draw2DImage(images, irr::core::position2d<irr::s32>(0,0));
        Button(obj[0], irr::core::position2d<irr::s32>(280, 94), play_rect);
        if (font) {
            for (size_t i = 0; i < score.size(); i++)
                font->draw(score[i].c_str(), irr::core::rect<irr::s32>(130, 10, 300, 500), irr::video::SColor(255,0,0,0));
        }
        driver->endScene();
    }
}

LeaderBoard::~LeaderBoard()
{
}
