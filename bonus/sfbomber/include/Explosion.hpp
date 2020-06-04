/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Explosion
*/

#pragma once

#include "GameObject.hpp"

class Explosion : public GameObject {
    public:
        Explosion(Animation const &anim, mystruct::vector3f const &pos);
        ~Explosion();
        void draw(std::shared_ptr<sf::RenderWindow>, sf::Sprite) const;
        void update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed);
        mystruct::vector3f getPos() const;
        GameObject::ObjTypes getType() const;
        bool do_remove() const;

    protected:
        Animation _anim;
        mystruct::vector3f _pos;
    private:
};
