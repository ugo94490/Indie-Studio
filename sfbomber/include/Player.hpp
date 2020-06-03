/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#pragma once

#include "Bomb.hpp"

class Player : public GameObject {
    public:
        Player(bool ia = false, mystruct::vector3f pos = mystruct::vector3f(), unsigned int id = 1);
        ~Player();
        void draw(std::shared_ptr<sf::RenderWindow>, sf::Sprite) const;
        void update(std::list<std::shared_ptr<GameObject>> &objs);
        mystruct::vector3f getPos() const;
        GameObject::ObjTypes getType() const;
        bool do_remove() const;
        void handle_input(void);
        void collide(std::list<std::shared_ptr<GameObject>> &objs);
        void assignAnim();
        void plantBomb(std::list<std::shared_ptr<GameObject>> &objs);
        int getPlanted() const;
        void setPlanted(int planted);
        int getPower() const;
        mystruct::vector3f getNearest(mystruct::vector3f const &pos);

    protected:
    private:
        unsigned int _id;
        bool _ia;
        bool _alive;
        mystruct::vector3f _pos;
        mystruct::vector3f _speed;
        bool _planting;
        int _speedmul;
        int _max_bombs;
        int _planted;
        int _power;
        bool _throughwall;
        sf::Keyboard::Key _leftkey;
        sf::Keyboard::Key _rightkey;
        sf::Keyboard::Key _upkey;
        sf::Keyboard::Key _downkey;
        sf::Keyboard::Key _bombkey;
        int _animnb;
        std::vector<Animation> _anims;
};