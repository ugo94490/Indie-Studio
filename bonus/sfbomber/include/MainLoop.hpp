/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MainLoop
*/

#include "Game.hpp"

class MainLoop
{
    private:
        std::shared_ptr<sf::RenderWindow> _window;
    public:
        MainLoop();
        ~MainLoop();
        void do_loop();
        std::shared_ptr<sf::RenderWindow> getWindow() const;
};