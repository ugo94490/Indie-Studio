/*
** EPITECH PROJECT, 2020
** sfbomber
** File description:
** Ground
*/

#include "Ground.hpp"

Ground::Ground(float x, float y, float z) : _anim(groundAnim)
{
    _pos.x = x;
    _pos.y = y;
    _pos.z = z;
}

Ground::~Ground()
{
}

void Ground::draw(std::shared_ptr<sf::RenderWindow> window, sf::Sprite sprite) const
{
    mystruct::intRect myrect = _anim.getActualRect();
    sf::IntRect sfrect(myrect.left, myrect.top, myrect.width, myrect.height);
    sf::Vector2f pos(_pos.x - myrect.width / 2, _pos.z + BLOCK_SIZE / 2 - myrect.height);

    sprite.setPosition(pos);
    sprite.setTextureRect(sfrect);
    window->draw(sprite);
}

void Ground::update(std::list<std::shared_ptr<GameObject>> &objs)
{
}

GameObject::ObjTypes Ground::getType() const
{
    return (ObjTypes::GROUND);
}

mystruct::vector3f Ground::getPos() const
{
    return (_pos);
}

bool Ground::do_remove() const
{
    return (false);
}