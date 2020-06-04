/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SolidWall
*/

#pragma once

#include "GameObject.hpp"

class SolidWall : public GameObject {
    public:
        SolidWall(float x, float y, float z);
        ~SolidWall();
        void draw(std::shared_ptr<sf::RenderWindow>, sf::Sprite) const;
        void update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed);
        mystruct::vector3f getPos() const;
        GameObject::ObjTypes getType() const;
        void remove(std::list<std::shared_ptr<GameObject>> &objs);
        bool do_remove() const;

    protected:
        mystruct::vector3f _pos;
        Animation _anim;
    private:
};
