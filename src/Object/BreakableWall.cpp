/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BreakableWall
*/

#include "BreakableWall.hpp"
#include "Factory.hpp"

BreakableWall::BreakableWall(float x, float y, float z, scene::ISceneManager* smgr, video::IVideoDriver* driver) : _smgr(smgr), _driver(driver)
{
    scene::IAnimatedMesh* mesh = Factory::Check_mesh(smgr, "assets/textures/box.MD3");
    _pos = {x, y, z};
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, Factory::Check_load(driver, "assets/textures/box.jpg"));
    _exploded = false;
}

BreakableWall::BreakableWall(irr::core::vector3d<f32> pos, scene::ISceneManager* smgr, video::IVideoDriver* driver) : _smgr(smgr), _driver(driver)
{
    scene::IAnimatedMesh* mesh = Factory::Check_mesh(smgr, "assets/textures/box.MD3");
    _pos = pos;
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, Factory::Check_load(driver, "assets/textures/box.jpg"));
    _exploded = false;
}

BreakableWall::~BreakableWall()
{
    _node->remove();
}

void BreakableWall::tryAddPowerUp(std::list<std::shared_ptr<GameObject>> &objs) const
{
    int generate = std::rand() % 3;
    int power = std::rand() % 4;

    if (generate != 0)
        return;
    objs.push_back(std::shared_ptr<GameObject>(new Powerup(_pos, ObjTypes(POWERUP + 1 + power), _smgr, _driver)));
}

void BreakableWall::update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed)
{
    (void)timepassed;
    if (_exploded)
        return;
    for (auto it = objs.begin(); it != objs.end(); ++it) {
        if ((*it)->getType() == ObjTypes::EXPLOSION && (*it)->getPos() == _pos) {
            _exploded = true;
            tryAddPowerUp(objs);
            removeObj(objs, (*it));
            break;
        }
    }
}

GameObject::ObjTypes BreakableWall::getType() const
{
    return (ObjTypes::BREAKABLEWALL);
}

irr::core::vector3d<f32> BreakableWall::getPos() const
{
    return (_pos);
}

bool BreakableWall::do_remove() const
{
    return (_exploded);
}

scene::IAnimatedMeshSceneNode *BreakableWall::getNode() const
{
    return (_node);
}

void BreakableWall::setNode(scene::IAnimatedMeshSceneNode *node)
{
    _node = node;
}