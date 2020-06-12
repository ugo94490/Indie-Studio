/*
** EPITECH PROJECT, 2020
** sfbomber
** File description:
** Ground
*/

#include "Ground.hpp"
#include "Factory.hpp"

Ground::Ground(float x, float y, float z, scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    scene::IAnimatedMesh* mesh = Factory::Check_mesh(smgr, "assets/textures/box.MD3");
    _pos = {x, y, z};
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, Factory::Check_load(driver, "assets/textures/wall5.jpg"));
}

Ground::Ground(irr::core::vector3d<f32> pos, scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    scene::IAnimatedMesh* mesh = Factory::Check_mesh(smgr, "assets/textures/box.MD3");
    _pos = pos;
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, Factory::Check_load(driver, "assets/textures/wall5.jpg"));
}

Ground::~Ground()
{
    _node->remove();
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

scene::IAnimatedMeshSceneNode *Ground::getNode() const
{
    return (_node);
}

void Ground::setNode(scene::IAnimatedMeshSceneNode *node)
{
    _node = node;
}

void Ground::save(std::ofstream &stream)
{
    Save<Ground>::save(*this, stream);
}

std::ostream &operator<<(std::ostream &os, Ground const &ground)
{
    os << "Ground:" << std::endl;
    os << " posx: " << ground._pos.X << std::endl;
    os << " posz: " << ground._pos.Z << std::endl;
    return (os);
}