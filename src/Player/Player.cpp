/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#include "Player.hpp"
#include "Factory.hpp"

Player::Player(float x, float y, float z, scene::ISceneManager* smgr, video::IVideoDriver* driver, std::string name, irr::video::ITexture *skin, int id, bool ia)
{
    _pos = {x, y, z};
    _meshIdle = Factory::Check_mesh(smgr, std::string("assets/textures/chara" + std::to_string(id) + "_idle.MD3").c_str());
    _meshMove = Factory::Check_mesh(smgr, std::string("assets/textures/chara" + std::to_string(id) + "_walk.MD3").c_str());
    _node = smgr->addAnimatedMeshSceneNode(_meshIdle);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, Factory::Check_load(driver, std::string("assets/textures/chara" + std::to_string(id) + "_diffuse.jpg").c_str()));
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
    _throughbomb = false;
    _bombpierce = false;
    _invincbletime = 0;
    _buffscore = 0;
    _score = 0;
    _smgr = smgr;
    _driver = driver;
    _do_anim = false;
    _id = id;
    idx_chara = id - 1;
}

Player::Player(irr::core::vector3d<f32> pos, scene::ISceneManager* smgr, video::IVideoDriver* driver, std::string name, irr::video::ITexture *skin, int id, bool ia)
{
    _pos = pos;
    _meshIdle = Factory::Check_mesh(smgr, std::string("assets/textures/chara" + std::to_string(id) + "_idle.MD3").c_str());
    _meshMove = Factory::Check_mesh(smgr, std::string("assets/textures/chara" + std::to_string(id) + "_walk.MD3").c_str());
    _node = smgr->addAnimatedMeshSceneNode(_meshIdle);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, Factory::Check_load(driver, std::string("assets/textures/chara" + std::to_string(id) + "_diffuse.jpg").c_str()));
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
    _throughbomb = false;
    _bombpierce = false;
    _invincbletime = 0;
    _buffscore = 0;
    _score = 0;
    _smgr = smgr;
    _driver = driver;
    _do_anim = false;
    _id = id;
    idx_chara = id - 1;
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
    if (type == THROUGHBOMBUP)
        _throughbomb = true;
    if (type == FIRESUPERUP)
        _power += 20;
    if (type == BOMBPIERCEUP)
        _bombpierce = true;
    if (type == BOMBDOWN && _max_bombs > 1)
        _max_bombs -= 1;
    if (type == FIREDOWN && _power > 1)
        _power -= 1;
    if (type == SPEEDDOWN && _speedmul > 1)
        _speedmul -= 1;
    if (type == INVINCIBLEUP)
        _invincbletime = 10000;
    removeObj(objs, powerup);
}

void Player::collide(std::list<std::shared_ptr<GameObject>> &objs)
{
    ObjTypes type;;
    irr::core::vector3d<f32> pos;

    for (auto it = objs.begin(); it != objs.end(); ++it) {
        type = (*it)->getType();
        pos = (*it)->getPos();
        if (type == ObjTypes::EXPLOSION && _invincbletime <= 0 && collidePointObj(_pos, pos))
            _alive = false;
        else if (type >= ObjTypes::POWERUP && collide2objs(_pos, pos)) {
            collidePowerUp(objs, (*it));
            it = objs.begin();
        }
        else if ((type == ObjTypes::SOLIDWALL ||
        (type == ObjTypes::BREAKABLEWALL && !_throughwall)) && collide2objs(_pos + _speed, pos))
            collideWall();
        else if (type == ObjTypes::BOMB && !_throughbomb && collide2objs(_pos + _speed, pos) && !collide2objs(_pos, pos))
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
        _node->setMaterialTexture(0, Factory::Check_load(_driver, std::string("assets/textures/chara" + std::to_string(_id) + "_diffuse.jpg").c_str()));
    }
    _do_anim = new_anim;
    if (_speed.Z > 0)
        _node->setRotation({0, 180, 0});
    if (_speed.Z < 0)
        _node->setRotation({0, 0, 0});
    if (_speed.X > 0)
        _node->setRotation({0, -90, 0});
    if (_speed.X < 0)
        _node->setRotation({0, 90, 0});
}

void Player::update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed)
{
    setAnim();
    _timepassed = timepassed;
    _invincbletime -= timepassed;
    if (_invincbletime < 0)
        _invincbletime = 0;
    _speed.X *= (_timepassed / 1000.0);
    _speed.Y *= (_timepassed / 1000.0);
    _speed.Z *= (_timepassed / 1000.0);
    collide(objs);
    if (!_alive)
        return;
    _buffscore += timepassed;
    if (_buffscore >= 1000) {
        _score += 1;
        _buffscore = 0;
    }
    if (_planting)
        plantBomb(objs);
    _pos = _pos + _speed;
    _node->setPosition(_pos);
}

std::vector<std::vector<char>> Player::getTabDanger(std::list<std::shared_ptr<GameObject>> const &objs)
{
    std::vector<std::vector<char>> vec;
    int posx;
    int posz;
    GameObject::ObjTypes type;
    std::shared_ptr<GameObject> objptr = nullptr;

    for (int i = 0; i < 17; i++) {
        std::vector<char> temp;
        for (int j = 0; j < 17; j++)
            temp.push_back(1);
        vec.push_back(temp);
    }
    for (auto it : objs) {
        type = it->getType();
        posx = it->getPos().X / BLOCK_SIZE;
        posz = it->getPos().Z / BLOCK_SIZE;
        if (type == EXPLOSION)
            vec[posz][posx] = -1;
        if (type == BOMB) {
            vec[posz][posx] = -1;
            for (int i = 1; i <= 4 && (posx + i) < 17; i++) {
                objptr = getObjbyPos(objs, {(float)(posx + i) * BLOCK_SIZE, BLOCK_SIZE, (float)(posz) * BLOCK_SIZE});
                if (objptr && (objptr->getType() == SOLIDWALL || objptr->getType() == BREAKABLEWALL))
                    break;
                vec[posz][posx + i] = -1;
            }
            for (int i = 1; i <= 4 && (posx - i) >= 0; i++) {
                objptr = getObjbyPos(objs, {(float)(posx - i) * BLOCK_SIZE, BLOCK_SIZE, (float)(posz) * BLOCK_SIZE});
                if (objptr && (objptr->getType() == SOLIDWALL || objptr->getType() == BREAKABLEWALL))
                    break;
                vec[posz][posx - i] = -1;
            }
            for (int i = 1; i <= 3 && (posz + i) < 17; i++) {
                objptr = getObjbyPos(objs, {(float)(posx) * BLOCK_SIZE, BLOCK_SIZE, (float)(posz + i) * BLOCK_SIZE});
                if (objptr && (objptr->getType() == SOLIDWALL || objptr->getType() == BREAKABLEWALL))
                    break;
                vec[posz + i][posx] = -1;
            }
            for (int i = 1; i <= 4 && (posz - i) >= 0; i++) {
                objptr = getObjbyPos(objs, {(float)(posx) * BLOCK_SIZE, BLOCK_SIZE, (float)(posz - i) * BLOCK_SIZE});
                if (objptr && (objptr->getType() == SOLIDWALL || objptr->getType() == BREAKABLEWALL))
                    break;
                vec[posz - i][posx] = -1;
            }
        }
        if ((type == BREAKABLEWALL && !_throughwall) || type == SOLIDWALL)
            vec[posz][posx] = 0;
    }
    return (vec);
}

static int getDirectionToGo(int startx, int starty, std::vector<std::vector<char>> const &tab, int distance, int direction)
{
    int dist1 = 1000;
    int dist2 = 1000;
    int dist3 = 1000;
    int dist4 = 1000;

    if (tab[starty][startx] == 0 || distance > 10)
        return (10000);
    if (tab[starty][startx] != -1)
        return (distance);
    if (startx < 16 && direction != 2 && tab[starty][startx + 1] != 0)
        dist1 = getDirectionToGo(startx + 1, starty, tab, distance + 1, 1);
    if (startx > 0 && direction != 1 && tab[starty][startx - 1] != 0)
        dist2 = getDirectionToGo(startx - 1, starty, tab, distance + 1, 2);
    if (starty < 16 && direction != 4 && tab[starty + 1][startx] != 0)
        dist3 = getDirectionToGo(startx, starty + 1, tab, distance + 1, 3);
    if (starty > 0 && direction != 3 && tab[starty - 1][startx] != 0)
        dist4 = getDirectionToGo(startx, starty - 1, tab, distance + 1, 4);
    if (dist2 < dist1)
        dist1 = dist2;
    if (dist3 < dist1)
        dist1 = dist3;
    if (dist4 < dist1)
        dist1 = dist4;
    return (dist1);
}

void Player::IADodge(int posx, int posz, std::vector<std::vector<char>> tab)
{
    int distance = 1000;
    int temp = 0;

    if (tab[posz][posx] != -1)
        return;
    if ((temp = getDirectionToGo(posx + 1, posz, tab, 1, 1)) < distance) {
        distance = temp;
        _speed = {(float)(_speedmul * BLOCK_SIZE), 0, 0};
    }
    if ((temp = getDirectionToGo(posx - 1, posz, tab, 1, 2)) < distance) {
        distance = temp;
        _speed = {(float)(-_speedmul * BLOCK_SIZE), 0, 0};
    }
    if ((temp = getDirectionToGo(posx, posz + 1, tab, 1, 3)) < distance) {
        distance = temp;
        _speed = {0, 0, (float)(_speedmul * BLOCK_SIZE)};
    }
    if ((temp = getDirectionToGo(posx, posz - 1, tab, 1, 4)) < distance)
        _speed = {0, 0, (float)(-_speedmul * BLOCK_SIZE)};
}

void Player::ComputeIA(std::list<std::shared_ptr<GameObject>> const &objs)
{
    int posx = getNearest(_pos).X / BLOCK_SIZE;
    int posz = getNearest(_pos).Z / BLOCK_SIZE;
    std::vector<std::vector<char>> tab = getTabDanger(objs);

    IADodge(posx, posz, tab);
}

void Player::handle_input(Core *core, std::list<std::shared_ptr<GameObject>> const &objs)
{
    _planting = false;
    _speed = {0, 0, 0};
    if (_ia)
        return ComputeIA(objs);
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

bool Player::getPierce() const
{
    return (_bombpierce);
}

int Player::getScore(void) const
{
    return (_score);
}

std::string Player::getName()
{
    return (_name);
}