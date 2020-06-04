/*
** EPITECH PROJECT, 2020
** sfbomber
** File description:
** Ground
*/

#pragma once

#include "GameObject.hpp"

class Ground : public GameObject {
    public:
        Ground(float x, float y, float z);
        ~Ground();
        void draw(std::shared_ptr<sf::RenderWindow>, sf::Sprite) const;
        void update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed);
        mystruct::vector3f getPos() const;
        GameObject::ObjTypes getType() const;
        bool do_remove() const;

    protected:
        mystruct::vector3f _pos;
        Animation _anim;
    private:
};
