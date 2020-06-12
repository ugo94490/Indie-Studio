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
        Powerup(float x, float y, float z, ObjTypes const &type, scene::ISceneManager* smgr, video::IVideoDriver* driver);
        Powerup(irr::core::vector3d<f32> pos, ObjTypes const &type, scene::ISceneManager* smgr, video::IVideoDriver* driver);
        ~Powerup();
        void update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed);
        irr::core::vector3d<f32> getPos() const;
        GameObject::ObjTypes getType() const;
        bool do_remove() const;
        scene::IAnimatedMeshSceneNode *getNode() const;
        void setNode(scene::IAnimatedMeshSceneNode *node);
        void save(std::ofstream &stream);
        friend std::ostream &operator<<(std::ostream &os, Powerup const &powerup);

    protected:
        scene::IAnimatedMeshSceneNode *_node;
        irr::core::vector3d<f32> _pos;
        ObjTypes _type;
        bool _dead;
    private:
};
