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
        BreakableWall(float x, float y, float z, scene::ISceneManager* smgr, video::IVideoDriver* driver);
        BreakableWall(irr::core::vector3d<f32> pos, scene::ISceneManager* smgr, video::IVideoDriver* driver);
        ~BreakableWall();
        void update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed);
        irr::core::vector3d<f32> getPos() const;
        GameObject::ObjTypes getType() const;
        bool do_remove() const;
        void tryAddPowerUp(std::list<std::shared_ptr<GameObject>> &objs) const;

    protected:
        scene::IAnimatedMeshSceneNode *_node;
        irr::core::vector3d<f32> _pos;
        bool _exploded;
        scene::ISceneManager* _smgr;
        video::IVideoDriver* _driver;
    private:
};
