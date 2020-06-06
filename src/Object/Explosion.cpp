/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Explosion
*/

#include "Explosion.hpp"

Explosion::Explosion(float x, float y, float z, scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    scene::IAnimatedMesh* mesh = smgr->getMesh("assets/textures/box.MD3");
    _pos = {x, y, z};
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, driver->getTexture("assets/textures/box.jpg"));
}

Explosion::Explosion(irr::core::vector3d<f32> pos, scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    scene::IAnimatedMesh* mesh = smgr->getMesh("assets/textures/box.MD3");
    _pos = pos;
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, driver->getTexture("assets/textures/box.jpg"));
}

Explosion::~Explosion()
{
}

void Explosion::update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed)
{
    (void)objs;
    (void)timepassed;
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
    return (false);
}