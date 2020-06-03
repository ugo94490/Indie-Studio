/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Game
*/

#pragma once

#include <memory>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Player.hpp"
#include "SolidWall.hpp"
#include "BreakableWall.hpp"
#include "Ground.hpp"

class Game {
    public:
        Game(std::shared_ptr<sf::RenderWindow> window);
        ~Game();
        void loop();
        void draw() const;
        void handle_input();
        void removeDead();

    protected:
        bool _continue;
        std::list<std::shared_ptr<GameObject>> _objects;
        std::list<std::shared_ptr<Player>> _players;
        std::shared_ptr<sf::RenderWindow> _window;
        sf::Texture _texture;
        sf::Sprite _sprite;
    private:
};
