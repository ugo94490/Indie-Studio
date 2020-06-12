/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Load
*/

#include "Load.hpp"

std::vector<std::string> Load::strToWords(std::string const &str)
{
    std::istringstream iss(str);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss},
    std::istream_iterator<std::string>());

    return (results);
}

void Load::loadFloatInto(std::string const &str, float &to_load)
{
    float val = 0;

    try {
        val = std::stof(str);
    } catch (...) {
        throw (Exception("Invalid value to load float\n"));
        return;
    }
    to_load = val;
}

void Load::loadIntInto(std::string const &str, int &to_load)
{
    int val = 0;

    try {
        val = std::stoi(str);
    } catch (...) {
        throw (Exception("Invalid value to load int\n"));
        return;
    }
    to_load = val;
}

void Load::loadCharInto(std::string const &str, char &to_load)
{
    char val = 0;

    try {
        val = std::stoi(str);
    } catch (...) {
        throw (Exception("Invalid value to load char\n"));
        return;
    }
    to_load = val;
}

void Load::loadBoolInto(std::string const &str, bool &to_load)
{
    bool val = 0;

    try {
        val = std::stoi(str);
    } catch (...) {
        throw (Exception(std::string("Invalid value to load bool : " + str + "\n").c_str()));
        return;
    }
    if (val != 1 && val != 0) {
        throw (Exception(std::string("Invalid value to load bool : " + str + "\n").c_str()));
        return;
    }
    to_load = val;
}

Load::Load(std::string const &filepath, Core *core)
{
    _core = core;
    _idx = 0;
    readfile(filepath);
    for (; _idx < _tab.size(); _idx++)
        check_line_base();
}

std::string Load::loadName(std::vector<std::string> words)
{
    std::string str = "";

    for (auto it : words)
        if (it != "name:")
            str += it;
    if (str.size() < 2)
        return ("");
    str.pop_back();
    str = str.substr(1);
    return (str);
}

void Load::tryLoadPlayer()
{
    std::shared_ptr<Player> ptr = nullptr;
    PlayerLoad info;
    std::vector<std::string> words;

    _idx += 1;
    for (; _idx < _tab.size() && _tab[_idx].size() > 0 && _tab[_idx][0] == ' '; _idx++) {
        words = strToWords(_tab[_idx]);
        if (words.size() <= 1 || (words.size() != 2 && words[0] != "name:"))
            break;
        if (words[0] == "name:")
            info._name = loadName(words);
        if (words[0] == "posx:")
            loadFloatInto(words[1], info._pos.X);
        if (words[0] == "posz:")
            loadFloatInto(words[1], info._pos.Z);
        if (words[0] == "skin:")
            loadIntInto(words[1], info._skin);
        if (words[0] == "id_bomber:")
            loadIntInto(words[1], info._id_bomber);
        if (words[0] == "ia:")
            loadBoolInto(words[1], info._ia);
        if (words[0] == "alive:")
            loadBoolInto(words[1], info._alive);
        if (words[0] == "speedmul:")
            loadIntInto(words[1], info._speedmul);
        if (words[0] == "max_bombs:")
            loadIntInto(words[1], info._max_bombs);
        if (words[0] == "planted:")
            loadIntInto(words[1], info._planted);
        if (words[0] == "power:")
            loadIntInto(words[1], info._power);
        if (words[0] == "throughwall:")
            loadBoolInto(words[1], info._throughwall);
        if (words[0] == "throughbomb:")
            loadBoolInto(words[1], info._throughbomb);
        if (words[0] == "bombpierce:")
            loadBoolInto(words[1], info._bombpierce);
        if (words[0] == "invincibletime:")
            loadFloatInto(words[1], info._invincibletime);
        if (words[0] == "score:")
            loadIntInto(words[1], info._score);
        if (words[0] == "bind1:")
            loadCharInto(words[1], info._bind[0].second);
        if (words[0] == "bind2:")
            loadCharInto(words[1], info._bind[1].second);
        if (words[0] == "bind3:")
            loadCharInto(words[1], info._bind[2].second);
        if (words[0] == "bind4:")
            loadCharInto(words[1], info._bind[3].second);
        if (words[0] == "bind5:")
            loadCharInto(words[1], info._bind[4].second);
    }
    if (info._skin > 4 || info._skin <= 0)
        return;
    ptr = std::make_shared<Player>(info._pos, _core->smgr, _core->driver, info._name, nullptr, info._skin, info._ia);
    ptr->setScore(info._score);
    ptr->setPlanted(info._planted);
    ptr->setBomberId(info._id_bomber);
    ptr->setSpeedmul(info._speedmul);
    ptr->setAlive(info._alive);
    ptr->setMaxBombs(info._max_bombs);
    ptr->setPlanted(info._planted);
    ptr->setPower(info._power);
    ptr->setThroughwall(info._throughwall);
    ptr->setThroughbomb(info._throughbomb);
    ptr->setBombpierce(info._bombpierce);
    ptr->setInvincibleTime(info._invincibletime);
    ptr->_bind = info._bind;
    _players.push_back(ptr);
    _objects.push_back(ptr);
}

void Load::tryLoadGround()
{
    std::shared_ptr<Ground> ptr = nullptr;
    irr::core::vector3d<f32> pos = {0, 0, 0};
    std::vector<std::string> words;

    _idx += 1;
    for (; _idx < _tab.size() && _tab[_idx].size() > 0 && _tab[_idx][0] == ' '; _idx++) {
        words = strToWords(_tab[_idx]);
        if (words.size() != 2)
            break;
        if (words[0] == "posx:")
            loadFloatInto(words[1], pos.X);
        if (words[0] == "posz:")
            loadFloatInto(words[1], pos.Z);
    }
    ptr = std::make_shared<Ground>(pos, _core->smgr, _core->driver);
    _objects.push_back(ptr);
}

void Load::tryLoadSolidWall()
{
    std::shared_ptr<SolidWall> ptr = nullptr;
    irr::core::vector3d<f32> pos = {0, BLOCK_SIZE, 0};
    std::vector<std::string> words;

    _idx += 1;
    for (; _idx < _tab.size() && _tab[_idx].size() > 0 && _tab[_idx][0] == ' '; _idx++) {
        words = strToWords(_tab[_idx]);
        if (words.size() != 2)
            break;
        if (words[0] == "posx:")
            loadFloatInto(words[1], pos.X);
        if (words[0] == "posz:")
            loadFloatInto(words[1], pos.Z);
    }
    ptr = std::make_shared<SolidWall>(pos, _core->smgr, _core->driver);
    _objects.push_back(ptr);
}

void Load::tryLoadBreakableWall()
{
    std::shared_ptr<BreakableWall> ptr = nullptr;
    irr::core::vector3d<f32> pos = {0, BLOCK_SIZE, 0};
    std::vector<std::string> words;
    bool exploded = 0;

    _idx += 1;
    for (; _idx < _tab.size() && _tab[_idx].size() > 0 && _tab[_idx][0] == ' '; _idx++) {
        words = strToWords(_tab[_idx]);
        if (words.size() != 2)
            break;
        if (words[0] == "posx:")
            loadFloatInto(words[1], pos.X);
        if (words[0] == "posz:")
            loadFloatInto(words[1], pos.Z);
        if (words[0] == "exploded:")
            loadBoolInto(words[1], exploded);
    }
    ptr = std::make_shared<BreakableWall>(pos, _core->smgr, _core->driver);
    ptr->setExploded(exploded);
    _objects.push_back(ptr);
}

void Load::tryLoadPowerup()
{
    std::shared_ptr<Powerup> ptr = nullptr;
    irr::core::vector3d<f32> pos = {0, BLOCK_SIZE, 0};
    bool dead = 0;
    int type = GameObject::ObjTypes::POWERUP;
    GameObject::ObjTypes typeobj;
    std::vector<std::string> words;

    _idx += 1;
    for (; _idx < _tab.size() && _tab[_idx].size() > 0 && _tab[_idx][0] == ' '; _idx++) {
        words = strToWords(_tab[_idx]);
        if (words.size() != 2)
            break;
        if (words[0] == "posx:")
            loadFloatInto(words[1], pos.X);
        if (words[0] == "posz:")
            loadFloatInto(words[1], pos.Z);
        if (words[0] == "dead:")
            loadBoolInto(words[1], dead);
        if (words[0] == "type:")
            loadIntInto(words[1], type);
    }
    if (type == GameObject::ObjTypes::POWERUP)
        return;
    typeobj = GameObject::ObjTypes(type);
    ptr = std::make_shared<Powerup>(pos, typeobj, _core->smgr, _core->driver);
    ptr->setDead(dead);
    _objects.push_back(ptr);
}

void Load::tryLoadBomb()
{
    std::shared_ptr<Bomb> ptr = nullptr;
    irr::core::vector3d<f32> pos = {0, BLOCK_SIZE, 0};
    bool exploded = 0;
    float timedead = 0;
    int planternb = 0;
    Player *planter = NULL;
    std::vector<std::string> words;

    _idx += 1;
    for (; _idx < _tab.size() && _tab[_idx].size() > 0 && _tab[_idx][0] == ' '; _idx++) {
        words = strToWords(_tab[_idx]);
        if (words.size() != 2)
            break;
        if (words[0] == "posx:")
            loadFloatInto(words[1], pos.X);
        if (words[0] == "posz:")
            loadFloatInto(words[1], pos.Z);
        if (words[0] == "exploded:")
            loadBoolInto(words[1], exploded);
        if (words[0] == "timedead:")
            loadFloatInto(words[1], timedead);
        if (words[0] == "planter:")
            loadIntInto(words[1], planternb);
    }
    for (auto it : _players)
        if (it->getBomberId() == planternb)
            planter = &(*it);
    if (!planter)
        return;
    ptr = std::make_shared<Bomb>(pos, _core->smgr, _core->driver, planter);
    ptr->setExploded(exploded);
    ptr->setTimedead(timedead);
    _objects.push_back(ptr);
}

void Load::tryLoadExplosion()
{
    std::shared_ptr<Explosion> ptr = nullptr;
    irr::core::vector3d<f32> pos = {0, BLOCK_SIZE, 0};
    bool dead = 0;
    float timedead = 0;
    std::vector<std::string> words;

    _idx += 1;
    for (; _idx < _tab.size() && _tab[_idx].size() > 0 && _tab[_idx][0] == ' '; _idx++) {
        words = strToWords(_tab[_idx]);
        if (words.size() != 2)
            break;
        if (words[0] == "posx:")
            loadFloatInto(words[1], pos.X);
        if (words[0] == "posz:")
            loadFloatInto(words[1], pos.Z);
        if (words[0] == "dead:")
            loadBoolInto(words[1], dead);
        if (words[0] == "timedead:")
            loadFloatInto(words[1], timedead);
    }
    ptr = std::make_shared<Explosion>(pos, _core->smgr, _core->driver);
    ptr->setTimedead(timedead);
    ptr->setDead(dead);
    _objects.push_back(ptr);
}

void Load::check_line_base()
{
    if (_tab[_idx] == "Player:")
        tryLoadPlayer();
    if (_tab[_idx] == "Ground:")
        tryLoadGround();
    if (_tab[_idx] == "SolidWall:")
        tryLoadSolidWall();
    if (_tab[_idx] == "BreakableWall:")
        tryLoadBreakableWall();
    if (_tab[_idx] == "Powerup:")
        tryLoadPowerup();
    if (_tab[_idx] == "Bomb:")
        tryLoadBomb();
    if (_tab[_idx] == "Explosion:")
        tryLoadExplosion();
}

void Load::readfile(std::string const &filepath) {
    std::string line;
    std::ifstream in(filepath);

    if (!in.is_open()) {
        throw (Exception("Could not load file\n"));
        return;
    }
    while (getline(in,line))
        _tab.push_back(line);
    in.close();
}

std::list<std::shared_ptr<GameObject>> Load::getObjects() const
{
    return (_objects);
}

std::list<std::shared_ptr<Player>> Load::getPlayers() const
{
    return (_players);
}