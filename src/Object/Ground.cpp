/*
** EPITECH PROJECT, 2020
** sfbomber
** File description:
** Ground
*/

#include "Ground.hpp"

Ground::Ground(float x, float y, float z, scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    scene::IAnimatedMesh* mesh = smgr->getMesh("assets/textures/box.MD3");
    _pos = {x, y, z};
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, driver->getTexture("assets/textures/wall5.jpg"));
}

Ground::Ground(irr::core::vector3d<f32> pos, scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    scene::IAnimatedMesh* mesh = smgr->getMesh("assets/textures/box.MD3");
    _pos = pos;
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, driver->getTexture("assets/textures/wall5.jpg"));
}

Ground::~Ground()
{
}

void Ground::update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed)
{
    (void)objs;
    (void)timepassed;
}

GameObject::ObjTypes Ground::getType() const
{
    return (ObjTypes::GROUND);
}

irr::core::vector3d<f32> Ground::getPos() const
{
    return (_pos);
}

bool Ground::do_remove() const
{
    return (false);
}