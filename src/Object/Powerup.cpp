/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Powerup
*/

#include "Powerup.hpp"

Powerup::Powerup(float x, float y, float z, ObjTypes const &type, scene::ISceneManager* smgr, video::IVideoDriver* driver) : _type(type), _dead(false)
{
    scene::IAnimatedMesh* mesh = smgr->getMesh("assets/textures/power1.obj");
    _pos = {x, y, z};
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, driver->getTexture("assets/textures/power.png"));
}

Powerup::Powerup(irr::core::vector3d<f32> pos, ObjTypes const &type, scene::ISceneManager* smgr, video::IVideoDriver* driver) : _type(type), _dead(false)
{
    scene::IAnimatedMesh* mesh = smgr->getMesh("assets/textures/power1.obj");
    _pos = pos;
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, driver->getTexture("assets/textures/power.png"));
}

Powerup::~Powerup()
{
    _node->remove();
}

void Powerup::update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed)
{
    (void)timepassed;
    for (auto it = objs.begin(); it != objs.end(); ++it)
        if ((*it)->getType() == EXPLOSION && collide2objs((*it)->getPos(), _pos))
            _dead = true;
}

irr::core::vector3d<f32> Powerup::getPos() const
{
    return (_pos);
}

GameObject::ObjTypes Powerup::getType() const
{
    return (_type);
}

bool Powerup::do_remove() const
{
    return (_dead);
}

scene::IAnimatedMeshSceneNode *Powerup::getNode() const
{
    return (_node);
}

void Powerup::setNode(scene::IAnimatedMeshSceneNode *node)
{
    _node = node;
}