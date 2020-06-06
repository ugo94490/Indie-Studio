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
        Ground(float x, float y, float z, scene::ISceneManager* smgr, video::IVideoDriver* driver);
        Ground(irr::core::vector3d<f32> pos, scene::ISceneManager* smgr, video::IVideoDriver* driver);
        ~Ground();
        void update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed);
        irr::core::vector3d<f32> getPos() const;
        GameObject::ObjTypes getType() const;
        bool do_remove() const;

    protected:
        scene::IAnimatedMeshSceneNode *_node;
        irr::core::vector3d<f32> _pos;
    private:
};
