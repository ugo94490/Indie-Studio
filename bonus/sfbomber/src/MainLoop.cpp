/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MainLoop
*/

#include "MainLoop.hpp"

MainLoop::MainLoop()
{
    _window = std::shared_ptr<sf::RenderWindow>(new sf::RenderWindow
    (sf::VideoMode(240, 208), "Bomberman", sf::Style::Close | sf::Style::Resize));
    _window->setFramerateLimit(60);
    _window->setVerticalSyncEnabled(true);
}

MainLoop::~MainLoop()
{
}

void MainLoop::do_loop()
{
    std::shared_ptr<Game> game(new Game(_window));

    game->loop();
}

std::shared_ptr<sf::RenderWindow> MainLoop::getWindow() const
{
    return (_window);
}