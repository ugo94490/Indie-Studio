/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Powerup
*/

#include "Powerup.hpp"
#include "Factory.hpp"

Powerup::Powerup(float x, float y, float z, ObjTypes const &type, scene::ISceneManager* smgr, video::IVideoDriver* driver) : _type(type), _dead(false)
{
    std::string path;
    scene::IAnimatedMesh* mesh = Factory::Check_mesh(smgr, "assets/textures/power1.obj");
    _pos = {x, y, z};
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    if (_type == GameObject::BOMBUP)
        path = "assets/textures/bombup.png";
    if (_type == GameObject::FIREUP)
        path = "assets/textures/fireup.png";
    if (_type == GameObject::SPEEDUP)
        path = "assets/textures/speedup.png";
    if (_type == GameObject::THROUGHWALLUP)
        path = "assets/textures/throughwall.png";
    if (_type == GameObject::THROUGHBOMBUP)
        path = "assets/textures/throughbomb.png";
    if (_type == GameObject::FIRESUPERUP)
        path = "assets/textures/yellowflame.png";
    if (_type == GameObject::BOMBPIERCEUP)
        path = "assets/textures/crossbomb.png";
    if (_type == GameObject::BOMBDOWN)
        path = "assets/textures/bombdown.png";
    if (_type == GameObject::FIREDOWN)
        path = "assets/textures/blueflame.png";
    if (_type == GameObject::SPEEDDOWN)
        path = "assets/textures/speeddown.png";
    if (_type == GameObject::INVINCIBLEUP)
        path = "assets/textures/angry.png";
    _node->setMaterialTexture(0, Factory::Check_load(driver, path.c_str()));
}

Powerup::Powerup(irr::core::vector3d<f32> pos, ObjTypes const &type, scene::ISceneManager* smgr, video::IVideoDriver* driver) : _type(type), _dead(false)
{
    std::string path;
    scene::IAnimatedMesh* mesh = Factory::Check_mesh(smgr, "assets/textures/power1.obj");
    _pos = pos;
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    if (_type == GameObject::BOMBUP)
        path = "assets/textures/bombup.png";
    if (_type == GameObject::FIREUP)
        path = "assets/textures/fireup.png";
    if (_type == GameObject::SPEEDUP)
        path = "assets/textures/speedup.png";
    if (_type == GameObject::THROUGHWALLUP)
        path = "assets/textures/throughwall.png";
    if (_type == GameObject::THROUGHBOMBUP)
        path = "assets/textures/throughbomb.png";
    if (_type == GameObject::FIRESUPERUP)
        path = "assets/textures/yellowflame.png";
    if (_type == GameObject::BOMBPIERCEUP)
        path = "assets/textures/crossbomb.png";
    if (_type == GameObject::BOMBDOWN)
        path = "assets/textures/bombdown.png";
    if (_type == GameObject::FIREDOWN)
        path = "assets/textures/blueflame.png";
    if (_type == GameObject::SPEEDDOWN)
        path = "assets/textures/speeddown.png";
    if (_type == GameObject::INVINCIBLEUP)
        path = "assets/textures/angry.png";
    _node->setMaterialTexture(0, Factory::Check_load(driver, path.c_str()));
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

void Powerup::save(std::ofstream &stream)
{
    Save<Powerup>::save(*this, stream);
}

std::ostream &operator<<(std::ostream &os, Powerup const &powerup)
{
    os << "Powerup:" << std::endl;
    os << " posx: " << powerup._pos.X << std::endl;
    os << " posz: " << powerup._pos.Z << std::endl;
    os << " type: " << powerup._type << std::endl;
    os << " dead: " << powerup._dead << std::endl;
    return (os);
}