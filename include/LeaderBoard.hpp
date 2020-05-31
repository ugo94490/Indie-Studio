/*
** EPITECH PROJECT, 2020
** LeaderBoard.hpp
** File description:
** LeaderBoard.hpp
*/

#pragma once

#include "IModule.hpp"
#include "Event.hpp"

class LeaderBoard : public IModule
{
    public:
        LeaderBoard(irr::IrrlichtDevice *device, irr::video::IVideoDriver* driver, irr::scene::ISceneManager* smgr, irr::gui::IGUIEnvironment* guienv, Event *event);
        ~LeaderBoard();
        void Loop(std::vector<std::shared_ptr<IModule>> obj);
        void Button(std::shared_ptr<IModule> obj, irr::core::position2d<irr::s32>, std::vector<irr::core::rect<irr::s32>> rect);
        bool Button_bool(irr::core::position2d<irr::s32> pos, std::vector<irr::core::rect<irr::s32>> rect);
        void getScore(std::string path);
    private:
        irr::IrrlichtDevice *device;
        irr::video::IVideoDriver* driver;
        irr::scene::ISceneManager* smgr;
        irr::gui::IGUIEnvironment* guienv;
        irr::video::ITexture *images;
        irr::video::ITexture *button;
        Event *recv;
        std::vector<std::shared_ptr<IModule>> tab;
        irr::gui::IGUIFont *font;
        std::vector<std::string> score;
};
