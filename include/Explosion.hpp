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
        Explosion(float x, float y, float z, scene::ISceneManager* smgr, video::IVideoDriver* driver);
        Explosion(irr::core::vector3d<f32> pos, scene::ISceneManager* smgr, video::IVideoDriver* driver);
        ~Explosion();
        void update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed);
        irr::core::vector3d<f32> getPos() const;
        GameObject::ObjTypes getType() const;
        bool do_remove() const;

    protected:
        scene::IAnimatedMeshSceneNode *_node;
        irr::core::vector3d<f32> _pos;
    private:
};
