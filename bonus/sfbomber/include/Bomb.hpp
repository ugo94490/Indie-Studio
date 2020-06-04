/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb
*/

#pragma once

#include "GameObject.hpp"
#include "Explosion.hpp"

class Player;

class Bomb : public GameObject {
    public:
        Bomb(Player *planter, mystruct::vector3f pos);
        ~Bomb();
        void draw(std::shared_ptr<sf::RenderWindow>, sf::Sprite) const;
        void update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed);
        mystruct::vector3f getPos() const;
        GameObject::ObjTypes getType() const;
        bool do_remove() const;
        void explode(std::list<std::shared_ptr<GameObject>> &objs);

    protected:
        Player *_planter;
        mystruct::vector3f _pos;
        bool _exploded;
        Animation _anim;
    private:
};

#include "Player.hpp"