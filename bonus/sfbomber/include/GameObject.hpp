/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** GameObject
*/

#pragma once

#define BLOCK_SIZE 16

#include <memory>
#include <list>
#include <SFML/Graphics.hpp>
#include "Animation.hpp"

class GameObject {
    public:
        enum ObjTypes {
            GROUND,
            BOMB,
            EXPLOSION,
            BREAKABLEWALL,
            SOLIDWALL,
            PLAYER,
            POWERUP,
            BOMBUP,
            FIREUP,
            SPEEDUP,
            THROUGHWALLUP,
            THROUGHBOMBUP,
            FIRESUPERUP,
            BOMBPIERCEUP,
            BOMBDOWN,
            FIREDOWN,
            SPEEDDOWN,
            INVICIBLEUP
        };
        virtual ~GameObject() = default;
        virtual void draw(std::shared_ptr<sf::RenderWindow>, sf::Sprite) const = 0;
        virtual void update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed) = 0;
        virtual mystruct::vector3f getPos() const = 0;
        virtual GameObject::ObjTypes getType() const = 0;
        virtual bool do_remove() const = 0;
        static void removeObj(std::list<std::shared_ptr<GameObject>> &objs, std::shared_ptr<GameObject> to_remove) {objs.remove(to_remove);}
        static int collidePointObj(mystruct::vector3f point, mystruct::vector3f p2)
        {
            if ((point.x >= (p2.x + BLOCK_SIZE / 2))
            || (point.x <= (p2.x - BLOCK_SIZE / 2))
            || (point.z >= (p2.z + BLOCK_SIZE / 2))
            || (point.z <= (p2.z - BLOCK_SIZE / 2)))
                return (0);
            return (1);
        }
        static int collide2objs(mystruct::vector3f p1, mystruct::vector3f p2)
        {
            if (((p2.x - BLOCK_SIZE / 2) >= (p1.x + BLOCK_SIZE / 2))
            || ((p2.x + BLOCK_SIZE / 2) <= (p1.x - BLOCK_SIZE / 2))
            || ((p2.z - BLOCK_SIZE / 2) >= (p1.z + BLOCK_SIZE / 2))
            || ((p2.z + BLOCK_SIZE / 2) <= (p1.z - BLOCK_SIZE / 2)))
                return (0);
            return (1);
        }

    protected:
    private:
};
