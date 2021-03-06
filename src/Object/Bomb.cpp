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
    scene::IAnimatedMesh* mesh = Factory::Check_mesh(smgr, "assets/textures/bomb.obj");
    _pos = {x, y, z};
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, Factory::Check_load(driver, "assets/textures/Bomb_Diffuse.png"));
    _timedead = 4000;
}

Bomb::Bomb(irr::core::vector3d<f32> pos, scene::ISceneManager* smgr, video::IVideoDriver* driver, Player *planter) : _smgr(smgr), _driver(driver), _planter(planter), _exploded(false)
{
    scene::IAnimatedMesh* mesh = Factory::Check_mesh(smgr, "assets/textures/bomb.obj");
    _pos = pos;
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, Factory::Check_load(driver, "assets/textures/Bomb_Diffuse.png"));
    _timedead = 4000;
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
            else if (((*it)->getType() == BOMB || (*it)->getType() == POWERUP || (*it)->getType() == BREAKABLEWALL) && !_planter->getPierce() && collide2objs((*it)->getPos(), pos)) {
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
            else if (((*it)->getType() == BOMB || (*it)->getType() == POWERUP || (*it)->getType() == BREAKABLEWALL) && !_planter->getPierce() && collide2objs((*it)->getPos(), pos)) {
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
            else if (((*it)->getType() == BOMB || (*it)->getType() == POWERUP || (*it)->getType() == BREAKABLEWALL) && !_planter->getPierce() && collide2objs((*it)->getPos(), pos)) {
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
            else if (((*it)->getType() == BOMB || (*it)->getType() == POWERUP || (*it)->getType() == BREAKABLEWALL) && !_planter->getPierce() && collide2objs((*it)->getPos(), pos)) {
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
    _timedead -= timepassed;
    if (_timedead <= 0)
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

void Bomb::setExploded(bool exploded)
{
    _exploded = exploded;
}

void Bomb::setTimedead(float timedead)
{
    _timedead = timedead;
}

void Bomb::save(std::ofstream &stream)
{
    Save<Bomb>::save(*this, stream);
}

std::ostream &operator<<(std::ostream &os, Bomb const &bomb)
{
    os << "Bomb:" << std::endl;
    os << " posx: " << bomb._pos.X << std::endl;
    os << " posz: " << bomb._pos.Z << std::endl;
    os << " exploded: " << bomb._exploded << std::endl;
    os << " planter: " << bomb._planter->getBomberId() << std::endl;
    os << " timedead: " << bomb._timedead << std::endl;
    return (os);
}