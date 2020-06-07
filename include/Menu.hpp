/*
** EPITECH PROJECT, 2020
** Menu.hpp
** File description:
** Menu.hpp
*/

#pragma once

#include "IModule.hpp"
#include "Event.hpp"
#include "Core.hpp"
#include "Player.hpp"

class Menu : public IModule
{
    public:
        Menu(Core *obj);
        ~Menu();
        void Loop(std::vector<std::shared_ptr<IModule>> obj);
        void display_skin();
        void Game();
        void New_Game(int nb);
        void Load_Game();
        void select_nb_player();
        std::vector<std::pair<bool, std::string>> setBoolName(std::vector<std::pair<bool, std::string>> tab, int i);
        std::vector<std::pair<bool, std::string>> Skin_button( std::vector<std::pair<bool, std::string>> write, int nb);
        void Display_name(std::vector<std::pair<bool, std::string>> *write, bool *click);
        void getBind(std::vector<std::shared_ptr<Player>> player);
        std::vector<std::shared_ptr<Player>> create_player(std::vector<std::pair<bool, std::string>> write, int nb);
        std::shared_ptr<Player> createObject(std::string name, int skin);
        void bind_player(std::vector<std::shared_ptr<Player>> player, int i);
        std::vector<std::pair<bool, char>> setBoolBind(std::vector<std::pair<bool, char>> lol, int j);
        void getTouche(std::shared_ptr<Player> player, int j);
        bool check_touche(std::vector<std::shared_ptr<Player>> player);
    private:
        Core *core;
        irr::video::ITexture *white;
        irr::video::ITexture *black;
        irr::video::ITexture *red;
        irr::video::ITexture *green;
        irr::video::ITexture *blue;
        std::vector<irr::video::ITexture *> bomb;
        std::vector<irr::core::rect<irr::s32>> bomb_rect;
        std::vector<std::shared_ptr<IModule>> tab;
        std::vector<int> skin_nb;
        int p1;
        int p2;
        int p3;
        int p4;
};
