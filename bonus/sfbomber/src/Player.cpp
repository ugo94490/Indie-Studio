/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(bool ia, mystruct::vector3f pos, unsigned int id) : _id(id),
_ia(ia), _alive(true), _pos(pos), _planting(false), _speedmul(3),
_max_bombs(1), _planted(0), _power(2), _throughwall(false), _animnb(3), _timepassed(0),
_throughbomb(false), _bombpierce(false), _invincbletime(0)
{
    _speed = mystruct::vector3f();
    _anims = whiteBomberAnims;
    _leftkey = sf::Keyboard::Key::Left;
    _rightkey = sf::Keyboard::Key::Right;
    _upkey = sf::Keyboard::Key::Up;
    _downkey = sf::Keyboard::Key::Down;
    _bombkey = sf::Keyboard::Key::Return;
    if (_id == 2) {
        _anims = blackBomberAnims;
        _leftkey = sf::Keyboard::Key::Q;
        _rightkey = sf::Keyboard::Key::D;
        _upkey = sf::Keyboard::Key::Z;
        _downkey = sf::Keyboard::Key::S;
        _bombkey = sf::Keyboard::Key::Space;
    }
    if (_id == 3) {
        _anims = blueBomberAnims;
    }
    if (_id == 4) {
        _anims = orangeBomberAnims;
    }
}

Player::~Player()
{
}

void Player::draw(std::shared_ptr<sf::RenderWindow> window, sf::Sprite sprite) const
{
    mystruct::intRect myrect = _anims[_animnb].getActualRect();
    sf::IntRect sfrect(myrect.left, myrect.top, myrect.width, myrect.height);
    sf::Vector2f pos(_pos.x - myrect.width / 2, _pos.z + BLOCK_SIZE / 2 - myrect.height);

    sprite.setPosition(pos);
    sprite.setTextureRect(sfrect);
    window->draw(sprite);
}

void Player::assignAnim()
{
    if (!_alive) {
        _animnb = 4;
        _anims[_animnb].setDoAnim(true);
        return;
    }
    if (_speed.x > 0)
        _animnb = 2;
    if (_speed.x < 0)
        _animnb = 1;
    if (_speed.z > 0)
        _animnb = 3;
    if (_speed.z < 0)
        _animnb = 0;
    _anims[_animnb].setDoAnim(true);
    if (_speed.x == 0 && _speed.z == 0)
        _anims[_animnb].setDoAnim(false);
}

void Player::collideWall(std::list<std::shared_ptr<GameObject>> const &objs, mystruct::vector3f const &wallPos)
{
    mystruct::vector3f objective = getNearest(_pos);
    _speed.x = 0;
    _speed.z = 0;
    if (abs(_pos.x - objective.x) <= 2 && _pos.x != objective.x)
        _pos.x = objective.x;
    if (abs(_pos.z - objective.z) <= 2 && _pos.z != objective.z)
        _pos.z = objective.z;
    if (abs(_pos.x - objective.x) >= 10)
        return;
    if (abs(_pos.z - objective.z) >= 10)
        return;
    if (objective.x > _pos.x)
        _speed.x = (_speedmul * BLOCK_SIZE);
    if (objective.x < _pos.x)
        _speed.x = -(_speedmul * BLOCK_SIZE);
    if (objective.z > _pos.z)
        _speed.z = (_speedmul * BLOCK_SIZE);
    if (objective.z < _pos.z)
        _speed.z = -(_speedmul * BLOCK_SIZE);
    _speed.x *= (_timepassed / 1000.0);
    _speed.z *= (_timepassed / 1000.0);
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
    if (type == INVICIBLEUP)
        _invincbletime = 10000;
    removeObj(objs, powerup);
}

void Player::collide(std::list<std::shared_ptr<GameObject>> &objs)
{
    ObjTypes type;;
    mystruct::vector3f pos;

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
            collideWall(objs, pos);
        else if (type == ObjTypes::BOMB && !_throughbomb && collide2objs(_pos + _speed, pos) && !collide2objs(_pos, pos))
            collideWall(objs, pos);
    }
}

void Player::plantBomb(std::list<std::shared_ptr<GameObject>> &objs)
{
    ObjTypes type;
    mystruct::vector3f plantpos = getNearest(_pos);

    if (_planted >= _max_bombs)
        return;
    for (auto it = objs.begin(); it != objs.end(); ++it) {
        type = (*it)->getType();
        if ((type == ObjTypes::BOMB || type == ObjTypes::BREAKABLEWALL || type == ObjTypes::SOLIDWALL)
        && collide2objs(plantpos, (*it)->getPos()))
            return;
    }
    objs.push_back(std::shared_ptr<GameObject>(new Bomb(this, plantpos)));
    _planted += 1;
}

void Player::update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed)
{
    _timepassed = timepassed;
    _invincbletime -= timepassed;
    if (_invincbletime < 0)
        _invincbletime = 0;
    assignAnim();
    _speed.x *= (_timepassed / 1000.0);
    _speed.y *= (_timepassed / 1000.0);
    _speed.z *= (_timepassed / 1000.0);
    collide(objs);
    _anims[_animnb].update();
    if (!_alive)
        return;
    _pos = _pos + _speed;
    if (_planting)
        plantBomb(objs);
}

std::vector<std::vector<char>> Player::getTabDanger(std::list<std::shared_ptr<GameObject>> const &objs)
{
    std::vector<std::vector<char>> vec;
    int posx;
    int posz;
    GameObject::ObjTypes type;
    std::shared_ptr<GameObject> objptr = nullptr;

    for (int i = 0; i < 13; i++) {
        std::vector<char> temp;
        for (int j = 0; j < 15; j++)
            temp.push_back(1);
        vec.push_back(temp);
    }
    for (auto it : objs) {
        type = it->getType();
        posx = it->getPos().x / BLOCK_SIZE;
        posz = it->getPos().z / BLOCK_SIZE;
        if (type == EXPLOSION)
            vec[posz][posx] = -3;
        if (type == BOMB) {
            if (_throughbomb)
                vec[posz][posx] = -1;
            else
                vec[posz][posx] = -2;
            for (int i = 1; i <= 4 && (posx + i) < 15; i++) {
                objptr = getObjbyPos(objs, {(float)(posx + i) * BLOCK_SIZE + BLOCK_SIZE / 2, 0, (float)(posz) * BLOCK_SIZE + BLOCK_SIZE / 2});
                if (objptr && (objptr->getType() == SOLIDWALL || objptr->getType() == BREAKABLEWALL || objptr->getType() == BOMB))
                    break;
                vec[posz][posx + i] = -1;
            }
            for (int i = 1; i <= 4 && (posx - i) >= 0; i++) {
                objptr = getObjbyPos(objs, {(float)(posx - i) * BLOCK_SIZE + BLOCK_SIZE / 2, 0, (float)(posz) * BLOCK_SIZE + BLOCK_SIZE / 2});
                if (objptr && (objptr->getType() == SOLIDWALL || objptr->getType() == BREAKABLEWALL || objptr->getType() == BOMB))
                    break;
                vec[posz][posx - i] = -1;
            }
            for (int i = 1; i <= 4 && (posz + i) < 13; i++) {
                objptr = getObjbyPos(objs, {(float)(posx) * BLOCK_SIZE + BLOCK_SIZE / 2, 0, (float)(posz + i) * BLOCK_SIZE + BLOCK_SIZE / 2});
                if (objptr && (objptr->getType() == SOLIDWALL || objptr->getType() == BREAKABLEWALL || objptr->getType() == BOMB))
                    break;
                vec[posz + i][posx] = -1;
            }
            for (int i = 1; i <= 4 && (posz - i) >= 0; i++) {
                objptr = getObjbyPos(objs, {(float)(posx) * BLOCK_SIZE + BLOCK_SIZE / 2, 0, (float)(posz - i) * BLOCK_SIZE + BLOCK_SIZE / 2});
                if (objptr && (objptr->getType() == SOLIDWALL || objptr->getType() == BREAKABLEWALL || objptr->getType() == BOMB))
                    break;
                vec[posz - i][posx] = -1;
            }
        }
        if (type == BREAKABLEWALL && _throughwall)
            vec[posz][posx] = 2;
        if ((type == BREAKABLEWALL && !_throughwall) || type == SOLIDWALL)
            vec[posz][posx] = 0;
    }
    for (auto it : objs) {
        type = it->getType();
        posx = it->getPos().x / BLOCK_SIZE;
        posz = it->getPos().z / BLOCK_SIZE;
        if (type == BREAKABLEWALL && _throughwall)
            vec[posz][posx] = 2;
        else if (type == BREAKABLEWALL || type == SOLIDWALL)
            vec[posz][posx] = 0;
    }
    return (vec);
}

int Player::getDirectionToGoDef(int startx, int starty, std::vector<std::vector<char>> const &tab, int distance, int direction)
{
    int dist1 = 1000;
    int dist2 = 1000;
    int dist3 = 1000;
    int dist4 = 1000;

    if (starty > 12 || startx > 14 || starty < 0 || startx < 0)
        return (1000);
    if (tab[starty][startx] == -3 || tab[starty][startx] == 0 || (tab[starty][startx] == -2 && distance != 0) || distance > 10)
        return (1000);
    if (tab[starty][startx] != -1)
        return (distance);
    if (startx < 14 && direction != 2 && tab[starty][startx + 1] != 0)
        dist1 = getDirectionToGoDef(startx + 1, starty, tab, distance + 1, 1);
    if (startx > 0 && direction != 1 && tab[starty][startx - 1] != 0)
        dist2 = getDirectionToGoDef(startx - 1, starty, tab, distance + 1, 2);
    if (starty < 12 && direction != 4 && tab[starty + 1][startx] != 0)
        dist3 = getDirectionToGoDef(startx, starty + 1, tab, distance + 1, 3);
    if (starty > 0 && direction != 3 && tab[starty - 1][startx] != 0)
        dist4 = getDirectionToGoDef(startx, starty - 1, tab, distance + 1, 4);
    if (dist2 < dist1)
        dist1 = dist2;
    if (dist3 < dist1)
        dist1 = dist3;
    if (dist4 < dist1)
        dist1 = dist4;
    return (dist1);
}

int Player::IADodge(int posx, int posz, std::vector<std::vector<char>> tab)
{
    int distance = 1000;
    int temp = 0;

    if (tab[posz][posx] >= 0)
        return (2);
    if ((temp = getDirectionToGoDef(posx + 1, posz, tab, 1, 1)) < distance) {
        distance = temp;
        _speed = {(float)(_speedmul * BLOCK_SIZE), 0, 0};
    }
    if ((temp = getDirectionToGoDef(posx - 1, posz, tab, 1, 2)) < distance) {
        distance = temp;
        _speed = {(float)(-_speedmul * BLOCK_SIZE), 0, 0};
    }
    if ((temp = getDirectionToGoDef(posx, posz + 1, tab, 1, 3)) < distance) {
        distance = temp;
        _speed = {0, 0, (float)(_speedmul * BLOCK_SIZE)};
    }
    if ((temp = getDirectionToGoDef(posx, posz - 1, tab, 1, 4)) < distance)
        _speed = {0, 0, (float)(-_speedmul * BLOCK_SIZE)};
    if (_speed.x != 0 || _speed.z != 0)
        return (1);
    return (0);
}

std::vector<std::vector<char>> Player::simulatePlant(int posx, int posz, std::vector<std::vector<char>> const &vec)
{
    std::vector<std::vector<char>> res = vec;

    if (_throughbomb)
        res[posz][posx] = -1;
    else
        res[posz][posx] = -2;
    for (int i = 1; i <= 4 && (posx + i) < 17; i++) {
        if (res[posz][posx + i] != 1)
            break;
        res[posz][posx + i] = -1;
    }
    for (int i = 1; i <= 4 && (posx - i) > 0; i++) {
        if (res[posz][posx - i] != 1)
            break;
        res[posz][posx - i] = -1;
    }
    for (int i = 1; i <= 4 && (posz + i) < 17; i++) {
        if (res[posz + i][posx] != 1)
            break;
        res[posz + i][posx] = -1;
    }
    for (int i = 1; i <= 4 && (posz - i) > 0; i++) {
        if (res[posz - i][posx] != 1)
            break;
        res[posz - i][posx] = -1;
    }
    return (res);
}

int Player::getDirectionToGoAtk(int startx, int starty, std::vector<std::vector<char>> const &tab, int distance, int direction)
{
    int dist1 = 1000;
    int dist2 = 1000;
    int dist3 = 1000;
    int dist4 = 1000;

    if (starty > 12 || startx > 14 || starty < 0 || startx < 0)
        return (1000);
    if ((tab[starty][startx] == 0 || tab[starty][startx] == 2) && ((startx % 2) == 1 || (starty % 2) == 1) && startx != 0 && starty != 0 && starty != 12 && startx != 14)
        return (distance);
    else if (tab[starty][startx] == 0 || distance > 10)
        return (1000);
    if (startx < 16 && direction != 2)
        dist1 = getDirectionToGoAtk(startx + 1, starty, tab, distance + 1, 1);
    if (startx > 0 && direction != 1)
        dist2 = getDirectionToGoAtk(startx - 1, starty, tab, distance + 1, 2);
    if (starty < 16 && direction != 4)
        dist3 = getDirectionToGoAtk(startx, starty + 1, tab, distance + 1, 3);
    if (starty > 0 && direction != 3)
        dist4 = getDirectionToGoAtk(startx, starty - 1, tab, distance + 1, 4);
    if (dist2 < dist1)
        dist1 = dist2;
    if (dist3 < dist1)
        dist1 = dist3;
    if (dist4 < dist1)
        dist1 = dist4;
    return (dist1);
}

void Player::IAAtk(int posx, int posz, std::vector<std::vector<char>> const &tab)
{
    int distance = 1000;
    int temp = 1000;

    if (tab[posz][posx] < 0)
        return;
    if ((temp = getDirectionToGoAtk(posx + 1, posz, tab, 1, 1)) < distance) {
        distance = temp;
        _speed = {(float)(_speedmul * BLOCK_SIZE), 0, 0};
    }
    if ((temp = getDirectionToGoAtk(posx - 1, posz, tab, 1, 2)) < distance) {
        distance = temp;
        _speed = {(float)(-_speedmul * BLOCK_SIZE), 0, 0};
    }
    if ((temp = getDirectionToGoAtk(posx, posz + 1, tab, 1, 3)) < distance) {
        distance = temp;
        _speed = {0, 0, (float)(_speedmul * BLOCK_SIZE)};
    }
    if ((temp = getDirectionToGoAtk(posx, posz - 1, tab, 1, 4)) < distance) {
        distance = temp;
        _speed = {0, 0, (float)(-_speedmul * BLOCK_SIZE)};
    }
    if (distance <= 1 || distance >= 1000) {
        _speed = {0, 0, 0};
        if (IADodge(posx, posz, simulatePlant(posx, posz, tab)) == 1)
            _planting = true;
        _speed = {0, 0, 0};
    }
}

void Player::ComputeIA(std::list<std::shared_ptr<GameObject>> const &objs)
{
    int posx = getNearest(_pos).x / BLOCK_SIZE;
    int posz = getNearest(_pos).z / BLOCK_SIZE;
    int do_dodge;
    mystruct::vector3f speedsave;
    std::vector<std::vector<char>> tab = getTabDanger(objs);

    if (posx < 0 || posx > 14 || posz < 0 || posz > 14)
        return;
    IAAtk(posx, posz, tab);
    do_dodge = IADodge(posx, posz, tab);
    speedsave = _speed;
    if (do_dodge == 2 && _speed.x > 0 && IADodge(posx + 1, posz, tab) != 2) {
        _speed = {0, 0, 0};
        return;
    }
    if (do_dodge == 2 && _speed.x < 0 && IADodge(posx - 1, posz, tab) != 2) {
        _speed = {0, 0, 0};
        return;
    }
    if (do_dodge == 2 && _speed.z > 0 && IADodge(posx, posz + 1, tab) != 2) {
        _speed = {0, 0, 0};
        return;
    }
    if (do_dodge == 2 && _speed.z < 0 && IADodge(posx, posz - 1, tab) != 2) {
        _speed = {0, 0, 0};
        return;
    }
    _speed = speedsave;
}

void Player::handle_input(std::list<std::shared_ptr<GameObject>> const &objs)
{
    _planting = false;
    _speed = mystruct::vector3f();
    if (_ia)
        return ComputeIA(objs);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(_leftkey)))
        _speed.x += -(_speedmul * BLOCK_SIZE);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(_rightkey)))
         _speed.x += (_speedmul * BLOCK_SIZE);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(_upkey)))
         _speed.z += -(_speedmul * BLOCK_SIZE);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(_downkey)))
         _speed.z += (_speedmul * BLOCK_SIZE);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(_bombkey)))
        _planting = true;
}

GameObject::ObjTypes Player::getType() const
{
    return (ObjTypes::PLAYER);
}

mystruct::vector3f Player::getPos() const
{
    return (_pos);
}

bool Player::do_remove() const
{
    if (_anims[_animnb].getDestroy() && _anims[_animnb].getNbCycles() == 0)
        return (true);
    return (false);
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

mystruct::vector3f Player::getNearest(mystruct::vector3f const &pos)
{
    mystruct::vector3f vec;
    int div1 = pos.x / BLOCK_SIZE;
    int div2 = pos.z / BLOCK_SIZE;

    vec.x = div1 * BLOCK_SIZE + BLOCK_SIZE / 2;
    vec.z = div2 * BLOCK_SIZE + BLOCK_SIZE / 2;
    return (vec);
}

bool Player::getPierce() const
{
    return (_bombpierce);
}