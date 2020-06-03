/*
** EPITECH PROJECT, 2020
** sfbomber
** File description:
** BreakableWall
*/

#include "BreakableWall.hpp"

BreakableWall::BreakableWall(float x, float y, float z) : _anim(breakableWallAnim), _exploded(false)
{
    _pos.x = x;
    _pos.y = y;
    _pos.z = z;
}

BreakableWall::~BreakableWall()
{
}

void BreakableWall::draw(std::shared_ptr<sf::RenderWindow> window, sf::Sprite sprite) const
{
    mystruct::intRect myrect = _anim.getActualRect();
    sf::IntRect sfrect(myrect.left, myrect.top, myrect.width, myrect.height);
    sf::Vector2f pos(_pos.x - myrect.width / 2, _pos.z + BLOCK_SIZE / 2 - myrect.height);

    sprite.setPosition(pos);
    sprite.setTextureRect(sfrect);
    window->draw(sprite);
}

void BreakableWall::update(std::list<std::shared_ptr<GameObject>> &objs)
{
    _anim.update();
    if (_exploded)
        return;
    for (auto it = objs.begin(); it != objs.end(); ++it) {
        if ((*it)->getType() == ObjTypes::EXPLOSION && (*it)->getPos() == _pos) {
            _exploded = true;
            _anim.setDoAnim(true);
            break;
        }
    }
}

GameObject::ObjTypes BreakableWall::getType() const
{
    return (ObjTypes::BREAKABLEWALL);
}

mystruct::vector3f BreakableWall::getPos() const
{
    return (_pos);
}

bool BreakableWall::do_remove() const
{
    if (_anim.getDestroy() && _anim.getNbCycles() == 0)
        return (true);
    return (false);
}