/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Game
*/

#include "Game.hpp"
#include <iostream>

Game::Game(std::shared_ptr<sf::RenderWindow> window)
{
    std::string line;
    std::ifstream myfile ("./map.txt");

    _window = window;
    _continue = true;
    _texture.loadFromFile("assets/spritesheet.png");
    if (!myfile.is_open())
        return;
    for (int i = 0; !myfile.eof(); i++) {
        getline (myfile, line);
        for (int j = 0; line[j]; j++) {
            _objects.push_back(std::shared_ptr<GameObject>(new Ground(BLOCK_SIZE / 2 + j * BLOCK_SIZE, 0, BLOCK_SIZE / 2 + i * BLOCK_SIZE)));
            if (line[j] == 'X')
                _objects.push_back(std::shared_ptr<GameObject>(new SolidWall(BLOCK_SIZE / 2 + j * BLOCK_SIZE, 0, BLOCK_SIZE / 2 + i * BLOCK_SIZE)));
            if (line[j] == 'o')
                _objects.push_back(std::shared_ptr<GameObject>(new BreakableWall(BLOCK_SIZE / 2 + j * BLOCK_SIZE, 0, BLOCK_SIZE / 2 + i * BLOCK_SIZE)));
        }
    }
    myfile.close();
    std::shared_ptr<Player> player1(new Player(false, mystruct::vector3f(BLOCK_SIZE * 1.5, 0, BLOCK_SIZE * 1.5)));
    _objects.push_back(player1);
    _players.push_back(player1);
    _sprite.setTexture(_texture);
}

Game::~Game()
{

}

void Game::draw() const
{
    _window->clear(sf::Color::Black);
    for (int i = 0; i <= 6; i++)
        for (auto it = _objects.begin(); it != _objects.end(); ++it)
            if ((*it)->getType() == i)
                (*it)->draw(_window, _sprite);
    _window->display();
}

void Game::handle_input()
{
    if (_window->isOpen()) {
        sf::Event event;
        while (_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                _window->close();
        }
        for (auto it = _players.begin(); it != _players.end(); ++it)
            (*it)->handle_input();
    }
}

void Game::removeDead()
{
    for (auto it = _objects.begin(); it != _objects.end(); ++it) {
        if ((*it)->do_remove()) {
            GameObject::removeObj(_objects, (*it));
            it = _objects.begin();
        }
    }
}

void Game::loop()
{
    while (_continue && _window->isOpen()) {
        handle_input();
        for (auto it = _objects.begin(); it != _objects.end(); ++it)
            (*it)->update(_objects);
        removeDead();
        draw();
    }
}
