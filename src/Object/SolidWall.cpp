/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SolidWall
*/

#include "SolidWall.hpp"

SolidWall::SolidWall(float x, float y, float z, scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    scene::IAnimatedMesh* mesh = smgr->getMesh("assets/textures/box.MD3");
    _pos = {x, y, z};
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, driver->getTexture("assets/textures/brick.jpg"));
}

SolidWall::SolidWall(irr::core::vector3d<f32> pos, scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    scene::IAnimatedMesh* mesh = smgr->getMesh("assets/textures/box.MD3");
    _pos = pos;
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, driver->getTexture("assets/textures/brick.jpg"));
}

SolidWall::~SolidWall()
{
}

void SolidWall::update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed)
{
    (void)timepassed;
    (void)objs;
}

GameObject::ObjTypes SolidWall::getType() const
{
    return (ObjTypes::SOLIDWALL);
}

irr::core::vector3d<f32> SolidWall::getPos() const
{
    return (_pos);
}

bool SolidWall::do_remove() const
{
    return (false);
}