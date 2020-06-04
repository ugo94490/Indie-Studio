/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb
*/

#include "Bomb.hpp"

Bomb::Bomb(Player *planter, mystruct::vector3f pos) : _planter(planter), _pos(pos), _exploded(false), _anim(bombAnim)
{
}

Bomb::~Bomb()
{
}

void Bomb::draw(std::shared_ptr<sf::RenderWindow> window, sf::Sprite sprite) const
{
    mystruct::intRect myrect = _anim.getActualRect();
    sf::IntRect sfrect(myrect.left, myrect.top, myrect.width, myrect.height);
    sf::Vector2f pos(_pos.x - myrect.width / 2, _pos.z + BLOCK_SIZE / 2 - myrect.height);

    sprite.setPosition(pos);
    sprite.setTextureRect(sfrect);
    window->draw(sprite);
}

void Bomb::explode(std::list<std::shared_ptr<GameObject>> &objs)
{
    int power = _planter->getPower();
    std::shared_ptr<GameObject> exp = nullptr;
    int flag = 0;
    mystruct::vector3f pos;

    _exploded = true;
    _planter->setPlanted(_planter->getPlanted() - 1);
    objs.push_back(std::shared_ptr<GameObject>(new Explosion(centerExplosionAnim, _pos)));
    for (int i = 1; i <= power; i++) {
        flag = 0;
        pos = mystruct::vector3f(_pos.x + BLOCK_SIZE * i, 0, _pos.z);
        if (i == power)
            exp = std::shared_ptr<GameObject>(new Explosion(rightExplosionAnim, pos));
        else
            exp = std::shared_ptr<GameObject>(new Explosion(leftRightExplosionAnim, pos));
        for (auto it = objs.begin(); it != objs.end(); ++it)
            if ((*it)->getType() == ObjTypes::SOLIDWALL && collide2objs((*it)->getPos(), pos)) {
                flag = 1;
                break;
            }
            else if (((*it)->getType() == ObjTypes::BREAKABLEWALL || (*it)->getType() == ObjTypes::POWERUP) && collide2objs((*it)->getPos(), pos)) {
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
        pos = mystruct::vector3f(_pos.x - BLOCK_SIZE * i, 0, _pos.z);
        if (i == power)
            exp = std::shared_ptr<GameObject>(new Explosion(leftExplosionAnim, pos));
        else
            exp = std::shared_ptr<GameObject>(new Explosion(leftRightExplosionAnim, pos));
        for (auto it = objs.begin(); it != objs.end(); ++it)
            if ((*it)->getType() == ObjTypes::SOLIDWALL && collide2objs((*it)->getPos(), pos)) {
                flag = 1;
                break;
            }
            else if (((*it)->getType() == ObjTypes::BREAKABLEWALL || (*it)->getType() == ObjTypes::POWERUP) && collide2objs((*it)->getPos(), pos)) {
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
        pos = mystruct::vector3f(_pos.x, 0, _pos.z + BLOCK_SIZE * i);
        if (i == power)
            exp = std::shared_ptr<GameObject>(new Explosion(downExplosionAnim, pos));
        else
            exp = std::shared_ptr<GameObject>(new Explosion(upDownExplosionAnim, pos));
        for (auto it = objs.begin(); it != objs.end(); ++it)
            if ((*it)->getType() == ObjTypes::SOLIDWALL && collide2objs((*it)->getPos(), pos)) {
                flag = 1;
                break;
            }
            else if (((*it)->getType() == ObjTypes::BREAKABLEWALL || (*it)->getType() == ObjTypes::POWERUP) && collide2objs((*it)->getPos(), pos)) {
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
        pos = mystruct::vector3f(_pos.x, 0, _pos.z - BLOCK_SIZE * i);
        if (i == power)
            exp = std::shared_ptr<GameObject>(new Explosion(upExplosionAnim, pos));
        else
            exp = std::shared_ptr<GameObject>(new Explosion(upDownExplosionAnim, pos));
        for (auto it = objs.begin(); it != objs.end(); ++it)
            if ((*it)->getType() == ObjTypes::SOLIDWALL && collide2objs((*it)->getPos(), pos)) {
                flag = 1;
                break;
            }
            else if (((*it)->getType() == ObjTypes::BREAKABLEWALL || (*it)->getType() == ObjTypes::POWERUP) && collide2objs((*it)->getPos(), pos)) {
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
    _anim.update();
    if (_anim.getDestroy() && _anim.getNbCycles() == 0)
        return (explode(objs));
    for (auto it = objs.begin(); it != objs.end(); ++it) {
        if ((*it)->getType() == GameObject::EXPLOSION && collide2objs(_pos, (*it)->getPos()))
            return (explode(objs));
    }
}

mystruct::vector3f Bomb::getPos() const
{
    return (_pos);
}

GameObject::ObjTypes Bomb::getType() const
{
    return (ObjTypes::BOMB);
}

bool Bomb::do_remove() const
{
    return (_exploded);
}