/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb
*/

#include "Bomb.hpp"

Bomb::Bomb(float x, float y, float z, scene::ISceneManager* smgr, video::IVideoDriver* driver, Player *planter) : _smgr(smgr), _driver(driver), _planter(planter), _exploded(false)
{
    scene::IAnimatedMesh* mesh = smgr->getMesh("assets/textures/box.MD3");
    _pos = {x, y, z};
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, driver->getTexture("assets/textures/box.jpg"));
}

Bomb::Bomb(irr::core::vector3d<f32> pos, scene::ISceneManager* smgr, video::IVideoDriver* driver, Player *planter) : _smgr(smgr), _driver(driver), _planter(planter), _exploded(false)
{
    scene::IAnimatedMesh* mesh = smgr->getMesh("assets/textures/box.MD3");
    _pos = pos;
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, driver->getTexture("assets/textures/box.jpg"));
}

Bomb::~Bomb()
{
}

void Bomb::explode(std::list<std::shared_ptr<GameObject>> &objs)
{
    int power = _planter->getPower();
    std::shared_ptr<GameObject> exp = nullptr;
    int flag = 0;
    irr::core::vector3d<f32> pos;

    _exploded = true;
    _planter->setPlanted(_planter->getPlanted() - 1);
    objs.push_back(std::make_shared<Explosion>(pos, _smgr, _driver));
    for (int i = 1; i <= power; i++) {
        flag = 0;
        pos = irr::core::vector3d<f32>(_pos.X + BLOCK_SIZE * i, 0, _pos.Z);
        if (i == power)
            exp = std::make_shared<Explosion>(pos, _smgr, _driver);
        else
            exp = std::make_shared<Explosion>(pos, _smgr, _driver);
        for (auto it = objs.begin(); it != objs.end(); ++it)
            if ((*it)->getType() == SOLIDWALL && collide2objs((*it)->getPos(), pos)) {
                flag = 1;
                break;
            }
            else if (((*it)->getType() == BOMB || (*it)->getType() == POWERUP) && collide2objs((*it)->getPos(), pos)) {
                flag = 2;
                break;
            }
        if (flag != 1)
            objs.push_back(exp);
        if (flag != 0)
            break;
    }
    for (int i = 1; i <= power; i++) {
        flag = 0;
        pos = irr::core::vector3d<f32>(_pos.X - BLOCK_SIZE * i, 0, _pos.Z);
        if (i == power)
            exp = std::make_shared<Explosion>(pos, _smgr, _driver);
        else
            exp = std::make_shared<Explosion>(pos, _smgr, _driver);
        for (auto it = objs.begin(); it != objs.end(); ++it)
            if ((*it)->getType() == SOLIDWALL && collide2objs((*it)->getPos(), pos)) {
                flag = 1;
                break;
            }
            else if (((*it)->getType() == BOMB || (*it)->getType() == POWERUP) && collide2objs((*it)->getPos(), pos)) {
                flag = 2;
                break;
            }
        if (flag != 1)
            objs.push_back(exp);
        if (flag != 0)
            break;
    }
    for (int i = 1; i <= power; i++) {
        flag = 0;
        pos = irr::core::vector3d<f32>(_pos.X, 0, _pos.Z + BLOCK_SIZE * i);
        if (i == power)
            exp = std::make_shared<Explosion>(pos, _smgr, _driver);
        else
            exp = std::make_shared<Explosion>(pos, _smgr, _driver);
        for (auto it = objs.begin(); it != objs.end(); ++it)
            if ((*it)->getType() == SOLIDWALL && collide2objs((*it)->getPos(), pos)) {
                flag = 1;
                break;
            }
            else if (((*it)->getType() == BOMB || (*it)->getType() == POWERUP) && collide2objs((*it)->getPos(), pos)) {
                flag = 2;
                break;
            }
        if (flag != 1)
            objs.push_back(exp);
        if (flag != 0)
            break;
    }
    for (int i = 1; i <= power; i++) {
        flag = 0;
        pos = irr::core::vector3d<f32>(_pos.X, 0, _pos.Z - BLOCK_SIZE * i);
        if (i == power)
            exp = std::make_shared<Explosion>(pos, _smgr, _driver);
        else
            exp = std::make_shared<Explosion>(pos, _smgr, _driver);
        for (auto it = objs.begin(); it != objs.end(); ++it)
            if ((*it)->getType() == SOLIDWALL && collide2objs((*it)->getPos(), pos)) {
                flag = 1;
                break;
            }
            else if (((*it)->getType() == BOMB || (*it)->getType() == POWERUP) && collide2objs((*it)->getPos(), pos)) {
                flag = 2;
                break;
            }
        if (flag != 1)
            objs.push_back(exp);
        if (flag != 0)
            break;
    }
}

void Bomb::update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed)
{
    (void)timepassed;
    if (true)
        return (explode(objs));
    for (auto it = objs.begin(); it != objs.end(); ++it) {
        if ((*it)->getType() == EXPLOSION && collide2objs(_pos, (*it)->getPos()))
            return (explode(objs));
    }
}

irr::core::vector3d<f32> Bomb::getPos() const
{
    return (_pos);
}

GameObject::ObjTypes Bomb::getType() const
{
    return (BOMB);
}

bool Bomb::do_remove() const
{
    return (_exploded);
}