/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Powerup
*/

#pragma once

#include "GameObject.hpp"

class Powerup : public GameObject {
    public:
        Powerup(ObjTypes const &type, mystruct::vector3f const &pos);
        ~Powerup();
        void draw(std::shared_ptr<sf::RenderWindow>, sf::Sprite) const;
        void update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed);
        mystruct::vector3f getPos() const;
        GameObject::ObjTypes getType() const;
        bool do_remove() const;

    protected:
        ObjTypes _type;
        mystruct::vector3f _pos;
        Animation _anim;
        bool _dead;
    private:
};
