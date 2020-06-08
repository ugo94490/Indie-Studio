/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Explosion
*/

#include "Explosion.hpp"
#include "Factory.hpp"

Explosion::Explosion(float x, float y, float z, scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    scene::IAnimatedMesh* mesh = Factory::Check_mesh(smgr, "assets/textures/box.MD3");
    _pos = {x, y, z};
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, Factory::Check_load(driver, "assets/textures/box.jpg"));
    _dead = false;
    _start = std::chrono::steady_clock::now();
}

Explosion::Explosion(irr::core::vector3d<f32> pos, scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    scene::IAnimatedMesh* mesh = Factory::Check_mesh(smgr, "assets/textures/box.MD3");
    _pos = pos;
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, Factory::Check_load(driver, "assets/textures/box.jpg"));
    _dead = false;
    _start = std::chrono::steady_clock::now();
}

Explosion::~Explosion()
{
    _node->remove();
}

void Explosion::update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed)
{
    (void)objs;
    (void)timepassed;
    _end = std::chrono::steady_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count() > 600)
        _dead = true;
}

GameObject::ObjTypes Explosion::getType() const
{
    return (ObjTypes::EXPLOSION);
}

irr::core::vector3d<f32> Explosion::getPos() const
{
    return (_pos);
}

bool Explosion::do_remove() const
{
    return (_dead);
}

scene::IAnimatedMeshSceneNode *Explosion::getNode() const
{
    return (_node);
}

void Explosion::setNode(scene::IAnimatedMeshSceneNode *node)
{
    _node = node;
}