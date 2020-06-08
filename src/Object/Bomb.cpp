/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb
*/

#include "Bomb.hpp"
#include "Factory.hpp"

Bomb::Bomb(float x, float y, float z, scene::ISceneManager* smgr, video::IVideoDriver* driver, Player *planter) : _smgr(smgr), _driver(driver), _planter(planter), _exploded(false)
{
    scene::IAnimatedMesh* mesh = Factory::Check_mesh(smgr, "assets/textures/Regular_Bomb_Low_Poly.dae");
    _pos = {x, y, z};
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, Factory::Check_load(driver, "assets/textures/Bomb_Diffuse.png"));
    _start = std::chrono::steady_clock::now();
}

Bomb::Bomb(irr::core::vector3d<f32> pos, scene::ISceneManager* smgr, video::IVideoDriver* driver, Player *planter) : _smgr(smgr), _driver(driver), _planter(planter), _exploded(false)
{
    scene::IAnimatedMesh* mesh = Factory::Check_mesh(smgr, "assets/textures/Regular_Bomb_Low_Poly.dae");
    _pos = pos;
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, Factory::Check_load(driver, "assets/textures/Bomb_Diffuse.png"));
    _start = std::chrono::steady_clock::now();
}

Bomb::~Bomb()
{
    _node->remove();
}

void Bomb::explode(std::list<std::shared_ptr<GameObject>> &objs)
{
    int power = _planter->getPower();
    std::shared_ptr<GameObject> exp = nullptr;
    int flag = 0;
    irr::core::vector3d<f32> pos;

    _exploded = true;
    _planter->setPlanted(_planter->getPlanted() - 1);
    pos = irr::core::vector3d<f32>(_pos.X, BLOCK_SIZE, _pos.Z);
    exp = std::make_shared<Explosion>(pos, _smgr, _driver);
    objs.push_back(exp);
    for (int i = 1; i <= power; i++) {
        flag = 0;
        pos = irr::core::vector3d<f32>(_pos.X + BLOCK_SIZE * i, BLOCK_SIZE, _pos.Z);
        exp = std::make_shared<Explosion>(pos, _smgr, _driver);
        for (auto it = objs.begin(); it != objs.end(); ++it)
            if ((*it)->getType() == SOLIDWALL && collide2objs((*it)->getPos(), pos)) {
                flag = 1;
                break;
            }
            else if (((*it)->getType() == BOMB || (*it)->getType() == POWERUP || (*it)->getType() == BREAKABLEWALL) && collide2objs((*it)->getPos(), pos)) {
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
        pos = irr::core::vector3d<f32>(_pos.X - BLOCK_SIZE * i, BLOCK_SIZE, _pos.Z);
        exp = std::make_shared<Explosion>(pos, _smgr, _driver);
        for (auto it = objs.begin(); it != objs.end(); ++it)
            if ((*it)->getType() == SOLIDWALL && collide2objs((*it)->getPos(), pos)) {
                flag = 1;
                break;
            }
            else if (((*it)->getType() == BOMB || (*it)->getType() == POWERUP || (*it)->getType() == BREAKABLEWALL) && collide2objs((*it)->getPos(), pos)) {
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
        pos = irr::core::vector3d<f32>(_pos.X, BLOCK_SIZE, _pos.Z + BLOCK_SIZE * i);
        exp = std::make_shared<Explosion>(pos, _smgr, _driver);
        for (auto it = objs.begin(); it != objs.end(); ++it)
            if ((*it)->getType() == SOLIDWALL && collide2objs((*it)->getPos(), pos)) {
                flag = 1;
                break;
            }
            else if (((*it)->getType() == BOMB || (*it)->getType() == POWERUP || (*it)->getType() == BREAKABLEWALL) && collide2objs((*it)->getPos(), pos)) {
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
        pos = irr::core::vector3d<f32>(_pos.X, BLOCK_SIZE, _pos.Z - BLOCK_SIZE * i);
        exp = std::make_shared<Explosion>(pos, _smgr, _driver);
        for (auto it = objs.begin(); it != objs.end(); ++it)
            if ((*it)->getType() == SOLIDWALL && collide2objs((*it)->getPos(), pos)) {
                flag = 1;
                break;
            }
            else if (((*it)->getType() == BOMB || (*it)->getType() == POWERUP || (*it)->getType() == BREAKABLEWALL) && collide2objs((*it)->getPos(), pos)) {
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
    _end = std::chrono::steady_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count() > 4000)
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

scene::IAnimatedMeshSceneNode *Bomb::getNode() const
{
    return (_node);
}

void Bomb::setNode(scene::IAnimatedMeshSceneNode *node)
{
    _node = node;
}