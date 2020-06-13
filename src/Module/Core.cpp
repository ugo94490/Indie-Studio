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
#include "Factory.hpp"

Core::Core()
{
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
    images = Factory::Check_load(driver, "assets/Sprite/Menu.jpg");
    button = Factory::Check_load(driver, "assets/Sprite/Button/INDIE.png");
    title = Factory::Check_load(driver, "assets/Sprite/title.png");
    xbox = Factory::Check_load(driver, "assets/Sprite/xbox.jpg");
    other_back = Factory::Check_load(driver, "assets/Sprite/credit.jpg");
    splash_screen = Factory::Check_load(driver, "assets/Sprite/splash.jpg");
    cine = Factory::Check_load(driver, "assets/cinematic.png");
    battle_music = Sound::createMusic("assets/Sound/battle_music.ogg");
    menu_music = Sound::createMusic("assets/Sound/menu_music.ogg");
    explosion_sound = Sound::createMusic("assets/Sound/explosion_sound.ogg");
}

Core::~Core()
{
    delete recv;
    Sound::destroyMusic(menu_music);
    Sound::destroyMusic(battle_music);
    Sound::destroyMusic(explosion_sound);
    delete menu_music;
    delete battle_music;
    delete explosion_sound;
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
        if (std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count() > 4000)
            break;
        driver->endScene();
    }
}

void Core::Cinematic()
{
    int posx = 0;
    int posy = 0;
    static std::chrono::steady_clock::time_point _start = std::chrono::steady_clock::now();
    static std::chrono::steady_clock::time_point _end = std::chrono::steady_clock::now();

    while (device->run()) {
        _end = std::chrono::steady_clock::now();
        driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        driver->draw2DImage(images, irr::core::position2d<irr::s32>(0, 0));
        driver->draw2DImage(cine, irr::core::position2d<irr::s32>(640, 360), irr::core::rect<irr::s32>(posx, posy, posx + 640, posy + 360));
        driver->endScene();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count() > 66) {
            _start = _end;
            posx += 640;
            if (posx >= 10240) {
                posx = 0;
                posy += 360;
            }
            if (posx == 9600 && posy == 5760) {
                posx = 0;
                posy = 0;
            }
        }
        if (recv->eve.EventType == irr::EET_KEY_INPUT_EVENT && recv->eve.KeyInput.PressedDown == true)
            break;
    }
}

void Core::launch()
{
    Sound::playMusic(menu_music);
    Sound::setVolume(menu_music, volume);
    obj[0]->Loop(obj);
}