/*
** EPITECH PROJECT, 2020
** Core.cpp
** File description:
** Core.cpp
*/

#include "Core.hpp"
#include "Menu.hpp"
#include "Event.hpp"
#include "Game.hpp"
#include "HowTo.hpp"
#include "Credit.hpp"
#include "LeaderBoard.hpp"
#include "Settings.hpp"

Core::Core()
{
    std::string str = "assets/hometown.ogg";
    std::shared_ptr<IModule> ptr;
    device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1920, 1080));
    if (!device)
        throw(Exception ("Error window not open"));
    device->setWindowCaption(L"Indie Studio");
    volume = 10;
    driver = device->getVideoDriver();
    smgr = device->getSceneManager();
    guienv = device->getGUIEnvironment();
    recv = new Event();
    device->setEventReceiver(recv);
    obj = {ptr = std::make_shared<Menu>(this), ptr = std::make_shared<Game>(this), ptr = std::make_shared<LeaderBoard>(this), ptr = std::make_shared<Settings>(this), ptr = std::make_shared<HowTo>(this), ptr = std::make_shared<Credit>(this)};
    font = device->getGUIEnvironment()->getFont("assets/Font/FONT.png");
    if (font == 0)
        throw(Exception("Cant load font"));
    images = driver->getTexture("assets/Sprite/Menu.jpg");
    button = driver->getTexture("assets/Sprite/Button/INDIE.png");
    title = driver->getTexture("assets/Sprite/title.png");
    xbox = driver->getTexture("assets/Sprite/xbox.jpg");
    other_back = driver->getTexture("assets/Sprite/credit.jpg");
    splash_screen = driver->getTexture("assets/Sprite/splash.jpg");
    menu_music = Sound::createMusic(str);
}

Core::~Core()
{
    delete recv;
    Sound::destroyMusic(menu_music);
    delete menu_music;
	device->drop();
}

void Core::Splash()
{
    static std::chrono::steady_clock::time_point _start = std::chrono::steady_clock::now();
    static std::chrono::steady_clock::time_point _end = std::chrono::steady_clock::now();

    while (device->run()) {
        driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        driver->draw2DImage(splash_screen, irr::core::position2d<irr::s32>(0,0));
        _end = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count() > 5000)
            break;
        driver->endScene();
    }
}

void Core::launch()
{
    Sound::playMusic(menu_music);
    Sound::setVolume(menu_music, volume);
    obj[0]->Loop(obj);
}