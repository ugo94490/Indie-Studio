/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Explosion
*/

#include "Explosion.hpp"

Explosion::Explosion(Animation const &anim, mystruct::vector3f const &pos) : _anim(anim), _pos(pos)
{

}

Explosion::~Explosion()
{
}

void Explosion::draw(std::shared_ptr<sf::RenderWindow> window, sf::Sprite sprite) const
{
    mystruct::intRect myrect = _anim.getActualRect();
    sf::IntRect sfrect(myrect.left, myrect.top, myrect.width, myrect.height);
    sf::Vector2f pos(_pos.x - myrect.width / 2, _pos.z + BLOCK_SIZE / 2 - myrect.height);

    sprite.setPosition(pos);
    sprite.setTextureRect(sfrect);
    window->draw(sprite);
}

void Explosion::update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed)
{
    _anim.update();
}

GameObject::ObjTypes Explosion::getType() const
{
    return (ObjTypes::EXPLOSION);
}

mystruct::vector3f Explosion::getPos() const
{
    return (_pos);
}

bool Explosion::do_remove() const
{
    if (_anim.getDestroy() && _anim.getNbCycles() == 0)
        return (true);
    return (false);
}