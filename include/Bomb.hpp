/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb
*/

#pragma once

#include "GameObject.hpp"
#include "Explosion.hpp"

class Player;

class Bomb : public GameObject {
    public:
        Bomb(float x, float y, float z, scene::ISceneManager* smgr, video::IVideoDriver* driver, Player *planter);
        Bomb(irr::core::vector3d<f32> pos, scene::ISceneManager* smgr, video::IVideoDriver* driver, Player *planter);
        ~Bomb();
        void update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed);
        irr::core::vector3d<f32> getPos() const;
        GameObject::ObjTypes getType() const;
        bool do_remove() const;
        void explode(std::list<std::shared_ptr<GameObject>> &objs);

    protected:
        scene::IAnimatedMeshSceneNode *_node;
        scene::ISceneManager* _smgr;
        video::IVideoDriver* _driver;
        irr::core::vector3d<f32> _pos;
        Player *_planter;
        bool _exploded;
    private:
};

#include "Player.hpp"