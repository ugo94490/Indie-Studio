/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** GameObject
*/

#pragma once

#define BLOCK_SIZE 40

#include <irrlicht.h>
#include <memory>
#include "driverChoice.h"
#include <vector>
#include <utility>
#include <list>
#include <chrono>
using namespace irr;
#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif

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
            INVINCIBLEUP
        };
        virtual ~GameObject() = default;
        virtual void update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed) = 0;
        virtual irr::core::vector3d<f32> getPos() const = 0;
        virtual GameObject::ObjTypes getType() const = 0;
        virtual bool do_remove() const = 0;
        virtual scene::IAnimatedMeshSceneNode *getNode() const = 0;
        virtual void setNode(scene::IAnimatedMeshSceneNode *node) = 0;
        static void removeObj(std::list<std::shared_ptr<GameObject>> &objs, std::shared_ptr<GameObject> to_remove) {
            if (to_remove->getNode())
                to_remove->getNode()->setVisible(false);
            objs.remove(to_remove);
        }
        static int collidePointObj(irr::core::vector3d<f32> point, irr::core::vector3d<f32> p2)
        {
            if (((point.X + BLOCK_SIZE / 2) >= (p2.X + BLOCK_SIZE))
            || ((point.X + BLOCK_SIZE / 2) <= p2.X)
            || ((point.Z + BLOCK_SIZE / 2) >= (p2.Z + BLOCK_SIZE))
            || ((point.Z + BLOCK_SIZE / 2) <= p2.Z))
                return (0);
            return (1);
        }
        static int collide2objs(irr::core::vector3d<f32> p1, irr::core::vector3d<f32> p2)
        {
            if ((p2.X >= (p1.X + BLOCK_SIZE))
            || ((p2.X + BLOCK_SIZE) <= p1.X)
            || (p2.Z >= (p1.Z + BLOCK_SIZE))
            || ((p2.Z + BLOCK_SIZE) <= p1.Z))
                return (0);
            return (1);
        }
        static int collPointLine(irr::core::vector3d<f32> point, irr::core::vector3d<f32> p2)
        {
            if ((point.Z + BLOCK_SIZE / 2) >= (p2.Z + BLOCK_SIZE)
            || (point.Z + BLOCK_SIZE / 2) <= p2.Z)
                return (0);
            return (1);
        }
        static int collPointCol(irr::core::vector3d<f32> point, irr::core::vector3d<f32> p2)
        {
            if ((point.X + BLOCK_SIZE / 2) >= (p2.X + BLOCK_SIZE)
            || (point.X + BLOCK_SIZE / 2) <= p2.X)
                return (0);
            return (1);
        }
        static irr::core::vector3d<f32> getNearest(irr::core::vector3d<f32> const &pos)
        {
            irr::core::vector3d<f32> vec;
            int div1 = pos.X / BLOCK_SIZE;
            int div2 = pos.Z / BLOCK_SIZE;

            if ((pos.X - div1 * BLOCK_SIZE) < (BLOCK_SIZE / 2))
                vec.X = div1 * BLOCK_SIZE;
            else
                vec.X = (div1 + 1) * BLOCK_SIZE;
            if ((pos.Z - div2 * BLOCK_SIZE) < (BLOCK_SIZE / 2))
                vec.Z = div2 * BLOCK_SIZE;
            else
                vec.Z = (div2 + 1) * BLOCK_SIZE;
            vec.Y = BLOCK_SIZE;
            return (vec);
        }

    protected:
    private:
};
