/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(std::string name, irr::video::ITexture *skin)
{
    _name = name;
    _skin = skin;
    _pos = {0, 0, 0};
    _node = NULL;
    _speed = {0, 0, 0};
    _ia = false;
    _alive = true;
    _planting = false;
    _speedmul = 2;
    _max_bombs = 1;
    _planted = 0;
    _power = 2;
    _throughwall = false;
    _smgr = NULL;
    _driver = NULL;
}

Player::Player(float x, float y, float z, scene::ISceneManager* smgr, video::IVideoDriver* driver, std::string name, irr::video::ITexture *skin, bool ia)
{
    scene::IAnimatedMesh* mesh = smgr->getMesh("assets/textures/box.MD3");
    _pos = {x, y, z};
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, driver->getTexture("assets/textures/box.jpg"));
    _speed = {0, 0, 0};
    _name = name;
    _skin = skin;
    _ia = ia;
    _alive = true;
    _planting = false;
    _speedmul = 2;
    _max_bombs = 1;
    _planted = 0;
    _power = 2;
    _throughwall = false;
    _smgr = smgr;
    _driver = driver;
}

Player::Player(irr::core::vector3d<f32> pos, scene::ISceneManager* smgr, video::IVideoDriver* driver, std::string name, irr::video::ITexture *skin, bool ia)
{
    scene::IAnimatedMesh* mesh = smgr->getMesh("assets/textures/box.MD3");
    _pos = pos;
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, driver->getTexture("assets/textures/box.jpg"));
    _name = name;
    _skin = skin;
    _ia = ia;
    _alive = true;
    _planting = false;
    _speedmul = 2;
    _max_bombs = 1;
    _planted = 0;
    _power = 2;
    _throughwall = false;
    _smgr = smgr;
    _driver = driver;
}

Player::~Player()
{
}

void Player::collideWall()
{
    irr::core::vector3d<f32> objective = getNearest(_pos);
    _speed.Y = 0;
    _speed.Z = 0;
    if (abs(_pos.Y - objective.Y) <= 2 && _pos.Y != objective.Y)
        _pos.Y = objective.Y;
    if (abs(_pos.Z - objective.Z) <= 2 && _pos.Z != objective.Z)
        _pos.Z = objective.Z;
    if (abs(_pos.Y - objective.Y) >= 10)
        return;
    if (abs(_pos.Z - objective.Z) >= 10)
        return;
    if (objective.Y > _pos.Y)
        _speed.Y = (_speedmul * BLOCK_SIZE);
    if (objective.Y < _pos.Y)
        _speed.Y = -(_speedmul * BLOCK_SIZE);
    if (objective.Z > _pos.Z)
        _speed.Z = (_speedmul * BLOCK_SIZE);
    if (objective.Z < _pos.Z)
        _speed.Z = -(_speedmul * BLOCK_SIZE);
    _speed.Y *= (_timepassed / 1000.0);
    _speed.Z *= (_timepassed / 1000.0);
}

void Player::collidePowerUp(std::list<std::shared_ptr<GameObject>> &objs, std::shared_ptr<GameObject> powerup)
{
    ObjTypes type = powerup->getType();

    if (type == BOMBUP)
        _max_bombs += 1;
    if (type == FIREUP)
        _power += 1;
    if (type == SPEEDUP)
        _speedmul += 1;
    if (type == THROUGHWALLUP)
        _throughwall = true;
    removeObj(objs, powerup);
}

void Player::collide(std::list<std::shared_ptr<GameObject>> &objs)
{
    ObjTypes type;;
    irr::core::vector3d<f32> pos;

    for (auto it = objs.begin(); it != objs.end(); ++it) {
        type = (*it)->getType();
        pos = (*it)->getPos();
        if (type == ObjTypes::EXPLOSION && collidePointObj(_pos, pos))
            _alive = false;
        else if (type >= ObjTypes::POWERUP && collide2objs(_pos, pos)) {
            collidePowerUp(objs, (*it));
            it = objs.begin();
        }
        else if ((type == ObjTypes::SOLIDWALL ||
        (type == ObjTypes::BREAKABLEWALL && !_throughwall)) && collide2objs(_pos + _speed, pos))
            collideWall();
        else if (type == ObjTypes::BOMB && collide2objs(_pos + _speed, pos) && !collide2objs(_pos, pos))
            collideWall();
    }
}

void Player::plantBomb(std::list<std::shared_ptr<GameObject>> &objs)
{
    ObjTypes type;
    irr::core::vector3d<f32> plantpos = getNearest(_pos);

    if (_planted >= _max_bombs)
        return;
    for (auto it = objs.begin(); it != objs.end(); ++it) {
        type = (*it)->getType();
        if ((type == ObjTypes::BOMB || type == ObjTypes::BREAKABLEWALL || type == ObjTypes::SOLIDWALL)
        && collide2objs(plantpos, (*it)->getPos()))
            return;
    }
    objs.push_back(std::make_shared<Bomb>(plantpos, _smgr, _driver, this));
    _planted += 1;
}

void Player::update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed)
{
    _timepassed = timepassed;
    _speed.Y *= (_timepassed / 1000.0);
    _speed.Y *= (_timepassed / 1000.0);
    _speed.Z *= (_timepassed / 1000.0);
    collide(objs);
    if (!_alive)
        return;
    _pos = _pos + _speed;
    if (_planting)
        plantBomb(objs);
}

void Player::handle_input(void)
{
    _planting = false;
    _speed = {0, 0, 0};
    if (_ia)
        return;
    if (true)
        _speed.Y += -(_speedmul * BLOCK_SIZE);
    if (true)
         _speed.Y += (_speedmul * BLOCK_SIZE);
    if (true)
         _speed.Z += -(_speedmul * BLOCK_SIZE);
    if (true)
         _speed.Z += (_speedmul * BLOCK_SIZE);
    if (true)
        _planting = true;
}

GameObject::ObjTypes Player::getType() const
{
    return (ObjTypes::PLAYER);
}

irr::core::vector3d<f32> Player::getPos() const
{
    return (_pos);
}

bool Player::do_remove() const
{
    return (!_alive);
}

int Player::getPlanted() const
{
    return (_planted);
}

void Player::setPlanted(int planted)
{
    _planted = planted;
}

int Player::getPower() const
{
    return (_power);
}

irr::core::vector3d<f32> Player::getNearest(irr::core::vector3d<f32> const &pos)
{
    irr::core::vector3d<f32> vec;
    int div1 = pos.Y / BLOCK_SIZE;
    int div2 = pos.Z / BLOCK_SIZE;

    vec.Y = div1 * BLOCK_SIZE + BLOCK_SIZE / 2;
    vec.Z = div2 * BLOCK_SIZE + BLOCK_SIZE / 2;
    return (vec);
}

void Player::setBind(std::vector<std::pair<bool, char>> bind)
{
    _bind = bind;
}