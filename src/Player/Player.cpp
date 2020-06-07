/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(float x, float y, float z, scene::ISceneManager* smgr, video::IVideoDriver* driver, std::string name, irr::video::ITexture *skin, int id, bool ia)
{
    _pos = {x, y, z};
    _meshIdle = smgr->getMesh(std::string("assets/textures/chara" + std::to_string(id) + "_idle.MD3").c_str());
    _meshMove = smgr->getMesh(std::string("assets/textures/chara" + std::to_string(id) + "_walk.MD3").c_str());
    _node = smgr->addAnimatedMeshSceneNode(_meshIdle);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, driver->getTexture(std::string("assets/textures/chara" + std::to_string(id) + "_diffuse.jpg").c_str()));
    _speed = {0, 0, 0};
    _name = name;
    _skin = skin;
    _ia = ia;
    _alive = true;
    _planting = false;
    _speedmul = 3;
    _max_bombs = 1;
    _planted = 0;
    _power = 2;
    _throughwall = false;
    _smgr = smgr;
    _driver = driver;
    _do_anim = false;
    _id = id;
}

Player::Player(irr::core::vector3d<f32> pos, scene::ISceneManager* smgr, video::IVideoDriver* driver, std::string name, irr::video::ITexture *skin, int id, bool ia)
{
    _pos = pos;
    _meshIdle = smgr->getMesh(std::string("assets/textures/chara" + std::to_string(id) + "_idle.MD3").c_str());
    _meshMove = smgr->getMesh(std::string("assets/textures/chara" + std::to_string(id) + "_walk.MD3").c_str());
    _node = smgr->addAnimatedMeshSceneNode(_meshIdle);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, driver->getTexture(std::string("assets/textures/chara" + std::to_string(id) + "_diffuse.jpg").c_str()));
    _speed = {0, 0, 0};
    _name = name;
    _skin = skin;
    _ia = ia;
    _alive = true;
    _planting = false;
    _speedmul = 3;
    _max_bombs = 1;
    _planted = 0;
    _power = 2;
    _throughwall = false;
    _smgr = smgr;
    _driver = driver;
    _do_anim = false;
    _id = id;
}

Player::~Player()
{
    _node->remove();
}

void Player::collideWall()
{
    irr::core::vector3d<f32> objective = getNearest(_pos);
    _speed.X = 0;
    _speed.Z = 0;
    if (abs(_pos.X - objective.X) <= (BLOCK_SIZE / 10) && _pos.X != objective.X)
        _pos.X = objective.X;
    if (abs(_pos.Z - objective.Z) <= (BLOCK_SIZE / 10) && _pos.Z != objective.Z)
        _pos.Z = objective.Z;
    if (abs(_pos.X - objective.X) >= (BLOCK_SIZE * 0.75))
        return;
    if (abs(_pos.Z - objective.Z) >= (BLOCK_SIZE * 0.75))
        return;
    if (objective.X > _pos.X)
        _speed.X = (_speedmul * BLOCK_SIZE);
    if (objective.X < _pos.X)
        _speed.X = -(_speedmul * BLOCK_SIZE);
    if (objective.Z > _pos.Z)
        _speed.Z = (_speedmul * BLOCK_SIZE);
    if (objective.Z < _pos.Z)
        _speed.Z = -(_speedmul * BLOCK_SIZE);
    _speed.X *= (_timepassed / 1000.0);
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
        if (type == ObjTypes::EXPLOSION && collidePointObj(_pos, pos)) {
            _alive = false;
        }
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

void Player::setAnim()
{
    bool new_anim = false;

    if (_speed.X != 0 || _speed.Z != 0)
        new_anim = true;
    if (new_anim != _do_anim) {
        _node->remove();
        if (new_anim)
            _node = _smgr->addAnimatedMeshSceneNode(_meshMove);
        else
            _node = _smgr->addAnimatedMeshSceneNode(_meshIdle);
        _node->setPosition(_pos);
        _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        _node->setMaterialTexture(0, _driver->getTexture(std::string("assets/textures/chara" + std::to_string(_id) + "_diffuse.jpg").c_str()));
    }
    _do_anim = new_anim;
}

void Player::update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed)
{
    setAnim();
    _timepassed = timepassed;
    _speed.X *= (_timepassed / 1000.0);
    _speed.Y *= (_timepassed / 1000.0);
    _speed.Z *= (_timepassed / 1000.0);
    collide(objs);
    if (!_alive)
        return;
    _pos = _pos + _speed;
    if (_planting)
        plantBomb(objs);
    _node->setPosition(_pos);
}

void Player::handle_input(Core *core)
{
    _planting = false;
    _speed = {0, 0, 0};
    if (_ia)
        return;
    if (core->recv->eve.EventType == irr::EET_KEY_INPUT_EVENT && core->recv->eve.KeyInput.PressedDown == true
    && core->recv->eve.KeyInput.Char == _bind[1].second) {
        _speed.X += -(_speedmul * BLOCK_SIZE);
    }
    if (core->recv->eve.EventType == irr::EET_KEY_INPUT_EVENT && core->recv->eve.KeyInput.PressedDown == true
    && core->recv->eve.KeyInput.Char == _bind[3].second) {
         _speed.X += (_speedmul * BLOCK_SIZE);
    }
    if (core->recv->eve.EventType == irr::EET_KEY_INPUT_EVENT && core->recv->eve.KeyInput.PressedDown == true
    && core->recv->eve.KeyInput.Char == _bind[2].second) {
         _speed.Z += -(_speedmul * BLOCK_SIZE);
    }
    if (core->recv->eve.EventType == irr::EET_KEY_INPUT_EVENT && core->recv->eve.KeyInput.PressedDown == true
    && core->recv->eve.KeyInput.Char == _bind[0].second) {
         _speed.Z += (_speedmul * BLOCK_SIZE);
    }
    if (core->recv->eve.EventType == irr::EET_KEY_INPUT_EVENT && core->recv->eve.KeyInput.PressedDown == true
    && core->recv->eve.KeyInput.Char == _bind[4].second) {
        _planting = true;
    }
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
    int div1 = pos.X / BLOCK_SIZE;
    int div2 = pos.Z / BLOCK_SIZE;

    if ((pos.X - div1 * BLOCK_SIZE) < (BLOCK_SIZE / 2))
        vec.X = div1 * BLOCK_SIZE;
    else
        vec.X = (div1 + 1) * BLOCK_SIZE;
    if ((pos.Z - div2 * BLOCK_SIZE) < (BLOCK_SIZE / 2))
        vec.Z = div2 * BLOCK_SIZE;
    else
        vec.Z = (div2 + 1) * BLOCK_SIZE;
    vec.Y = BLOCK_SIZE;
    return (vec);
}

void Player::setBind(std::vector<std::pair<bool, char>> bind)
{
    _bind = bind;
}

void Player::setPos(irr::core::vector3d<f32> pos)
{
    _pos = pos;
}

scene::IAnimatedMeshSceneNode *Player::getNode() const
{
    return (_node);
}

void Player::setNode(scene::IAnimatedMeshSceneNode *node)
{
    _node = node;
}