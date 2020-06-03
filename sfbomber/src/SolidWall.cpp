/*
** EPITECH PROJECT, 2020
** sfbomber
** File description:
** SolidWall
*/

#include "SolidWall.hpp"

SolidWall::SolidWall(float x, float y, float z) : _anim(solidWallAnim)
{
    _pos.x = x;
    _pos.y = y;
    _pos.z = z;
}

SolidWall::~SolidWall()
{
}

void SolidWall::draw(std::shared_ptr<sf::RenderWindow> window, sf::Sprite sprite) const
{
    mystruct::intRect myrect = _anim.getActualRect();
    sf::IntRect sfrect(myrect.left, myrect.top, myrect.width, myrect.height);
    sf::Vector2f pos(_pos.x - myrect.width / 2, _pos.z + BLOCK_SIZE / 2 - myrect.height);

    sprite.setPosition(pos);
    sprite.setTextureRect(sfrect);
    window->draw(sprite);
}

void SolidWall::update(std::list<std::shared_ptr<GameObject>> &objs)
{
}

GameObject::ObjTypes SolidWall::getType() const
{
    return (ObjTypes::SOLIDWALL);
}

mystruct::vector3f SolidWall::getPos() const
{
    return (_pos);
}

bool SolidWall::do_remove() const
{
    return (false);
}