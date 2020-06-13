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
    std::shared_ptr<Player> white(new Player(false, mystruct::vector3f(BLOCK_SIZE * 1.5, 0, BLOCK_SIZE * 1.5), 1));
    std::shared_ptr<Player> black(new Player(false, mystruct::vector3f(BLOCK_SIZE * 13.5, 0, BLOCK_SIZE * 11.5), 2));
    std::shared_ptr<Player> blue(new Player(true, mystruct::vector3f(BLOCK_SIZE * 13.5, 0, BLOCK_SIZE * 1.5), 3));
    std::shared_ptr<Player> orange(new Player(true, mystruct::vector3f(BLOCK_SIZE * 1.5, 0, BLOCK_SIZE * 11.5), 4));
    _objects.push_back(white);
    _players.push_back(white);
    _objects.push_back(black);
    _players.push_back(black);
    _objects.push_back(blue);
    _players.push_back(blue);
    _objects.push_back(orange);
    _players.push_back(orange);
    _sprite.setTexture(_texture);
}

Game::~Game()
{

}

void Game::draw() const
{
    _window->clear(sf::Color::Black);
    for (int i = 0; i <= GameObject::ObjTypes::INVICIBLEUP; i++)
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
            (*it)->handle_input(_objects);
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

void Game::checkend()
{
    int alive = 0;

    for (auto it = _players.begin(); it != _players.end(); ++it)
        if (!(*it)->do_remove())
            alive += 1;
    if (alive <= 1)
        _continue = false;
}

void Game::loop()
{
    std::chrono::steady_clock::time_point _start = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point _end = std::chrono::steady_clock::now();
    float timepassed;

    while (_continue && _window->isOpen()) {
        _end = std::chrono::steady_clock::now();
        timepassed = std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count();
        _start = std::chrono::steady_clock::now();
        handle_input();
        for (auto it = _objects.begin(); it != _objects.end(); ++it)
            (*it)->update(_objects, timepassed);
        removeDead();
        draw();
        checkend();
    }
}
