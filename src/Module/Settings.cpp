/*
** EPITECH PROJECT, 2020
** Settings.cpp
** File description:
** Settings.cpp
*/

#include <vector>
#include <chrono>
#include "Settings.hpp"
#include "Rect.hpp"
#include "Factory.hpp"

Settings::Settings(Core *obj)
{
    core = obj;
}

void Settings::Loop(std::vector<std::shared_ptr<IModule>> obj)
{
    tab = obj;
    while (core->device->run()) {
        core->driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        core->driver->draw2DImage(core->images, irr::core::position2d<irr::s32>(0,0));
        if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(760, 814), back_rect) == true)
            break;
        if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(1187, 425), right_rect) == true)
            if (core->volume <= 90) {
                core->volume += 10;
                Sound::setVolume(core->menu_music, core->volume);
                Sound::setVolume(core->battle_music, core->volume);
                Sound::setVolume(core->explosion_sound, core->volume);
            }
        if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(533, 425), left_rect) == true)
            if (core->volume >= 10) {
                core->volume -= 10;
                Sound::setVolume(core->menu_music, core->volume);
                Sound::setVolume(core->battle_music, core->volume);
                Sound::setVolume(core->explosion_sound, core->volume);
            }
        auto s = std::to_string(core->volume);
        Factory::Factory::Button_bool(core, irr::core::position2d<irr::s32>(910, 490), touche_rect);
        core->font->draw(s.c_str(), irr::core::rect<irr::s32>(955 - (s.size() * 10), 520, 1010, 590), irr::video::SColor(255,0,0,0));
        core->font->draw(L"Volume", irr::core::rect<irr::s32>(955 - (7 * 10), 330, 1010, 400), irr::video::SColor(255,0,0,0));
        core->driver->endScene();
    }
}

Settings::~Settings()
{
}
