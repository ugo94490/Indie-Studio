/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BreakableWall
*/

#pragma once

#include "Powerup.hpp"

class BreakableWall : public GameObject {
    public:
        BreakableWall(float x, float y, float z);
        ~BreakableWall();
        void draw(std::shared_ptr<sf::RenderWindow>, sf::Sprite) const;
        void update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed);
        mystruct::vector3f getPos() const;
        GameObject::ObjTypes getType() const;
        bool do_remove() const;
        void tryAddPowerUp(std::list<std::shared_ptr<GameObject>> &objs) const;

    protected:
        mystruct::vector3f _pos;
        Animation _anim;
        bool _exploded;
    private:
};
