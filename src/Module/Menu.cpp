/*
** EPITECH PROJECT, 2020
** Menu.cpp
** File description:
** Menu.cpp
*/

#include <vector>
#include <string>
#include <iostream>
#include <chrono>
#include <map>
#include "Menu.hpp"
#include "Rect.hpp"
#include "Factory.hpp"

Menu::Menu(Core *obj)
{
    core = obj;
    white = Factory::Check_load(core->driver, "assets/Sprite/Button/white.png");
    black = Factory::Check_load(core->driver, "assets/Sprite/Button/black.png");
    green = Factory::Check_load(core->driver, "assets/Sprite/Button/green.png");
    red = Factory::Check_load(core->driver, "assets/Sprite/Button/red.png");
    bomb = {white, black, green, red};
    bomb_rect = {white_rect, black_rect, green_rect, red_rect};
    skin_ia = {{false, 0}, {false, 1}, {false, 2}, {false, 3}};
}

Menu::~Menu()
{
}

void Menu::Loop(std::vector<std::shared_ptr<IModule>> obj)
{
    if (tab.empty() == true)
        tab = obj;
    while (core->device->run()) {
        core->driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        core->driver->draw2DImage(core->images, irr::core::position2d<irr::s32>(0,0));
        core->driver->draw2DImage(core->title, irr::core::position2d<irr::s32>(760,100), irr::core::rect<irr::s32>(0, 0, 400, 151), 0, irr::video::SColor(255,255,255,255), true);
        if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(280, 94), play_rect) == true)
            Game();
        Factory::Button(core, tab[2], irr::core::position2d<irr::s32>(1240, 94), score_rect);
        Factory::Button(core, tab[3], irr::core::position2d<irr::s32>(280, 454), options_rect);
        Factory::Button(core, tab[4], irr::core::position2d<irr::s32>(1240, 454), rules_rect);
        Factory::Button(core, tab[5], irr::core::position2d<irr::s32>(280, 814), credit_rect);
        if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(1240, 814), quit_rect) == true)
            core->device->closeDevice();
        core->driver->endScene();
    }
}

void Menu::select_nb_player()
{
    int nb_player = 1;
    while (core->device->run()) {
        core->driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        core->driver->draw2DImage(core->images, irr::core::position2d<irr::s32>(0,0));
        if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(1187, 425), right_rect) == true) {
            if (nb_player < 4)
                nb_player += 1;
            auto s = std::to_string(nb_player);
        }
        if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(533, 425), left_rect) == true) {
            if (nb_player > 1)
                nb_player -= 1;
            auto s = std::to_string(nb_player);
        }
        Factory::Factory::Button_bool(core, irr::core::position2d<irr::s32>(910, 490), touche_rect);
        if (Factory::Factory::Button_bool(core, irr::core::position2d<irr::s32>(800, 814), play_rect) == true) {
            New_Game(nb_player);
            break;
        }
        if (Factory::Factory::Button_bool(core, irr::core::position2d<irr::s32>(64, 814), back_rect) == true)
            break;
        auto s = std::to_string(nb_player);
        core->font->draw(s.c_str(), irr::core::rect<irr::s32>(950, 520, 1010, 590), irr::video::SColor(255,0,0,0));
        core->font->draw(L"NOMBRE DE JOUEURS :", irr::core::rect<irr::s32>(750, 280, 1010, 350), irr::video::SColor(255,0,0,0));
        core->driver->endScene();
    }
}

void Menu::Game()
{
    while (core->device->run()) {
        core->driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        core->driver->draw2DImage(core->images, irr::core::position2d<irr::s32>(0,0));
        if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(280, 454), new_rect) == true) {
            select_nb_player();
            break;
        }
        if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(1240, 454), load_rect) == true) {
            Load_Game();
            break;
        }
        if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(760, 814), back_rect) == true)
            break;
        core->driver->endScene();
    }
}

void Menu::display_skin()
{
    core->driver->draw2DImage(bomb[skin_nb[0]], irr::core::position2d<irr::s32>(64 + (rectangle_rect[0].getWidth() - bomb_rect[skin_nb[0]].getWidth()) / 2, 280), bomb_rect[skin_nb[0]], 0, irr::video::SColor(255,255,255,255), true);
    if (p2 != -1)
        core->driver->draw2DImage(bomb[skin_nb[1]], irr::core::position2d<irr::s32>(528 + (rectangle_rect[0].getWidth() - bomb_rect[skin_nb[1]].getWidth()) / 2, 280), bomb_rect[skin_nb[1]], 0, irr::video::SColor(255,255,255,255), true);
    if (p3 != -1)
        core->driver->draw2DImage(bomb[skin_nb[2]], irr::core::position2d<irr::s32>(992 + (rectangle_rect[0].getWidth() - bomb_rect[skin_nb[2]].getWidth()) / 2, 280), bomb_rect[skin_nb[2]], 0, irr::video::SColor(255,255,255,255), true);
    if (p4 != -1)
        core->driver->draw2DImage(bomb[skin_nb[3]], irr::core::position2d<irr::s32>(1456 + (rectangle_rect[0].getWidth() - bomb_rect[skin_nb[3]].getWidth()) / 2, 280), bomb_rect[skin_nb[3]], 0, irr::video::SColor(255,255,255,255), true);
}

std::vector<std::pair<bool, std::string>> Menu::setBoolName(std::vector<std::pair<bool, std::string>> lol, int j)
{
    for (size_t i = 0; i < lol.size(); i++)
        lol[i].first = false;
    lol[j].first = true;
    return (lol);
}

std::vector<std::pair<bool, std::string>> Menu::Skin_button( std::vector<std::pair<bool, std::string>> write, int nb)
{
    (Factory::Button_bool(core, irr::core::position2d<irr::s32>(64, 280), rectangle_rect) == true && nb >= 1) ? (skin_nb[0] >= 3 ? skin_nb[0] = 0 : skin_nb[0]++) : 0;
    (Factory::Button_bool(core, irr::core::position2d<irr::s32>(528, 280), rectangle_rect) == true && nb >= 2) ? (skin_nb[1] >= 3 ? skin_nb[1] = 0 : skin_nb[1]++) : 0;
    (Factory::Button_bool(core, irr::core::position2d<irr::s32>(992, 280), rectangle_rect) == true && nb >= 3) ? (skin_nb[2] >= 3 ? skin_nb[2] = 0 : skin_nb[2]++) : 0;
    (Factory::Button_bool(core, irr::core::position2d<irr::s32>(1456, 280), rectangle_rect) == true && nb >= 4) ? (skin_nb[3] >= 3 ? skin_nb[3] = 0 : skin_nb[3]++) : 0;
    if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(64, 160), name_rect) == true && nb >= 1)
        write = setBoolName(write, 0);
    if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(528, 160), name_rect) && nb >= 2)
        write = setBoolName(write, 1);
    if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(992, 160), name_rect) && nb >= 3)
        write = setBoolName(write, 2);
    if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(1456, 160), name_rect) && nb >= 4)
        write = setBoolName(write, 3);
    return (write);
}

void Menu::Display_name(std::vector<std::pair<bool, std::string>> *write, bool *click)
{
    if (core->recv->eve.EventType == irr::EET_KEY_INPUT_EVENT && core->recv->eve.KeyInput.PressedDown == true && *click == false)
        for (size_t i = 0; i < (*write).size(); i++)
            if ((*write)[i].first == true) {
                *click = true;
                if (core->recv->eve.KeyInput.Char == 8 && (*write)[i].second.size() > 0)
                    (*write)[i].second.erase((*write)[i].second.size() - 1);
                else if (((core->recv->eve.KeyInput.Char >= 97 && core->recv->eve.KeyInput.Char <= 122)) && (*write)[i].second.size() < 14)
                    (*write)[i].second += core->recv->eve.KeyInput.Char;
            }
    if (core->font)
        for (size_t i = 0; i < (*write).size(); i++) {
            if ((*write)[i].second.size() > 0)
                core->font->draw((*write)[i].second.c_str(), input_rect[i], irr::video::SColor(255,0,0,0), true, true);
            core->font->draw(L"NAME :", input_name_rect[i], irr::video::SColor(255,0,0,0));
        }
}

std::shared_ptr<Player> Menu::createObject(std::string name, int skin, bool ia, int i)
{
    std::string str = (name.size() > 0) ? name : name_p[i];
    std::shared_ptr<Player> ptr = std::make_shared<Player>(0, 80, 0, core->smgr, core->driver, str, bomb[skin], skin + 1, ia);


    for (size_t j = 0; j < skin_ia.size(); j++)
        if (skin == skin_ia[j].second)
            skin_ia[j].first = true;
    ptr->_bind = bind_p[i];
    return (ptr);
}

std::shared_ptr<Player> Menu::createIA(int skin, int i)
{
    for (size_t j = 0; j < skin_ia.size(); j++)
        if (skin_ia[j].first == false) {
            skin = skin_ia[j].second;
            skin_ia[j].first = true;
            break;
        }
    std::shared_ptr<Player> ptr = std::make_shared<Player>(0, 80, 0, core->smgr, core->driver, name_p[i], bomb[skin], skin + 1, true);
    return (ptr);
}

std::vector<std::shared_ptr<Player>> Menu::create_player(std::vector<std::pair<bool, std::string>> write, int nb)
{
    std::vector<std::shared_ptr<Player>> player;

    for (int i = 0; i < nb; i++)
        player.push_back(createObject(write[i].second, skin_nb[i], false, i));
    return (player);
}

void Menu::New_Game(int nb)
{
    static bool click = false;
    static std::chrono::steady_clock::time_point _start = std::chrono::steady_clock::now();
    static std::chrono::steady_clock::time_point _end = std::chrono::steady_clock::now();
    std::vector<std::pair<bool, std::string>> write = {{false, ""}, {false, ""}, {false, ""}, {false, ""}};

    skin_nb = {p1 = 0, p2 = (nb >= 2) ? 0 : -1, p3 = (nb >= 3) ? 0 : -1, p4 = (nb >= 4) ? 0 : -1};
    while (core->device->run()) {
        core->driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        core->driver->draw2DImage(core->images, irr::core::position2d<irr::s32>(0,0));
        if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(64, 814), back_rect) == true)
            break;
        if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(1456, 814), play_rect) == true) {
            getBind(create_player(write, nb));
            break;
        }
        write = Skin_button(write, nb);
        _end = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count() > 500) {
            _start = std::chrono::steady_clock::now();
            click = false;
        }
        Display_name(&write, &click);
        display_skin();
        core->driver->endScene();
    }
}

std::vector<std::pair<bool, char>> Menu::setBoolBind(std::vector<std::pair<bool, char>> lol, int j)
{
    for (size_t i = 0; i < lol.size(); i++)
        lol[i].first = false;
    lol[j].first = true;
    return (lol);
}

void Menu::getTouche(std::shared_ptr<Player> player, int j)
{
    std::string str;

    if (core->recv->eve.EventType == irr::EET_KEY_INPUT_EVENT && core->recv->eve.KeyInput.PressedDown)
        for (size_t i = 0; i < player->_bind.size(); i++)
            if (player->_bind[i].first == true)
                if (((core->recv->eve.KeyInput.Char >= 97 && core->recv->eve.KeyInput.Char <= 122))) {
                    player->_bind[i].second = core->recv->eve.KeyInput.Char;
                    player->_bind[i].first = false;
                }
    if (core->font)
        for (size_t i = 0; i < player->_bind.size(); i++) {
            str = player->_bind[i].second;
            core->font->draw(str.c_str(), pos_bind_rect[j][i], irr::video::SColor(255,0,0,0), true, true);
        }
}

void Menu::bind_player(std::vector<std::shared_ptr<Player>> player, int i)
{
    if (Factory::Button_bool(core, pos_bind[i][0], touche_rect))
        player[i]->_bind = setBoolBind(player[i]->_bind, 0);
    if (Factory::Button_bool(core, pos_bind[i][1], touche_rect))
        player[i]->_bind = setBoolBind(player[i]->_bind, 1);
    if (Factory::Button_bool(core, pos_bind[i][2], touche_rect))
        player[i]->_bind = setBoolBind(player[i]->_bind, 2);
    if (Factory::Button_bool(core, pos_bind[i][3], touche_rect))
        player[i]->_bind = setBoolBind(player[i]->_bind, 3);
    if (Factory::Button_bool(core, pos_bind[i][4], touche_rect))
        player[i]->_bind = setBoolBind(player[i]->_bind, 4);
    getTouche(player[i], i);
}

bool Menu::check_touche(std::vector<std::shared_ptr<Player>> player)
{
    int count = 0;

    for (size_t i = 0; i < player.size(); i++) {
        for (size_t j = 0; j < player[i]->_bind.size(); j++) {
            for (size_t k = 0; k < player.size(); k++)
                for (size_t l = 0; l < player[k]->_bind.size(); l++)
                    if (player[i]->_bind[j].second == player[k]->_bind[l].second)
                        count++;
            if (count != 1)
                return (false);
            count = 0;
        }
    }
    return (true);
}

void Menu::getBind(std::vector<std::shared_ptr<Player>> player)
{
    (void)player;
    while (core->device->run()) {
        core->driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        core->driver->draw2DImage(core->images, irr::core::position2d<irr::s32>(0,0));
        if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(64, 814), back_rect) == true)
            break;
        if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(800, 814), play_rect) == true && check_touche(player)) {
            for (int i = player.size(); i < 4; i++)
                player.push_back(createIA(i, i));
            tab[1]->character.clear();
            tab[1]->character = player;
            tab[1]->save = 0;
            tab[1]->Loop(tab);
            break;
        }
        for (size_t i = 0; i < player.size(); i++)
            bind_player(player, i);
        core->driver->endScene();
    }
}

void Menu::Load_Game()
{
    while (core->device->run()) {
        core->driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        core->driver->draw2DImage(core->images, irr::core::position2d<irr::s32>(0,0));
        if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(64, 814), back_rect) == true)
            break;
        if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(120, 490), name_rect)) {
            tab[1]->save = 1;
            tab[1]->Loop(tab);
            break;
        }
        if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(760, 490), name_rect)) {
            tab[1]->save = 2;
            tab[1]->Loop(tab);
            break;
        }
        if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(1400, 490), name_rect)) {
            tab[1]->save = 3;
            tab[1]->Loop(tab);
            break;
        }
        core->font->draw(L"SAVE 1", irr::core::rect<irr::s32>(120, 490, 520, 590), irr::video::SColor(255,0,0,0), true, true);
        core->font->draw(L"SAVE 2", irr::core::rect<irr::s32>(760, 490, 1160, 590), irr::video::SColor(255,0,0,0), true, true);
        core->font->draw(L"SAVE 3", irr::core::rect<irr::s32>(1400, 490, 1800, 590), irr::video::SColor(255,0,0,0), true, true);
        core->driver->endScene();
    }
}