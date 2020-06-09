/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Powerup
*/

#include "Powerup.hpp"

Powerup::Powerup(ObjTypes const &type, mystruct::vector3f const &pos) : _type(type), _pos(pos), _dead(false)
{
    _anim = bombUpAnim;
    if (type == ObjTypes::FIREUP)
        _anim = fireUpAnim;
    if (type == ObjTypes::SPEEDUP)
        _anim = speedUpAnim;
    if (type == ObjTypes::THROUGHWALLUP)
        _anim = throughwallUpAnim;
    if (type == ObjTypes::THROUGHBOMBUP)
        _anim = throughbombUpAnim;
    if (type == ObjTypes::FIRESUPERUP)
        _anim = firesuperUpAnim;
    if (type == ObjTypes::BOMBPIERCEUP)
        _anim = bombpierceUpAnim;
    if (type == ObjTypes::BOMBDOWN)
        _anim = bombdownAnim;
    if (type == ObjTypes::FIREDOWN)
        _anim = firedownAnim;
    if (type == ObjTypes::SPEEDDOWN)
        _anim = speeddownAnim;
    if (type == ObjTypes::INVICIBLEUP)
        _anim = invincibleUpAnim;
}

Powerup::~Powerup()
{
}

void Powerup::draw(std::shared_ptr<sf::RenderWindow> window, sf::Sprite sprite) const
{
    mystruct::intRect myrect =_anim.getActualRect();
    sf::IntRect sfrect(myrect.left, myrect.top, myrect.width, myrect.height);
    sf::Vector2f pos(_pos.x - myrect.width / 2, _pos.z + BLOCK_SIZE / 2 - myrect.height);

    sprite.setPosition(pos);
    sprite.setTextureRect(sfrect);
    window->draw(sprite);
}

void Powerup::update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed)
{
    _anim.update();
    for (auto it = objs.begin(); it != objs.end(); ++it)
        if ((*it)->getType() == EXPLOSION && collide2objs((*it)->getPos(), _pos))
            _dead = true;
}

mystruct::vector3f Powerup::getPos() const
{
    return (_pos);
}

GameObject::ObjTypes Powerup::getType() const
{
    return (_type);
}

bool Powerup::do_remove() const
{
    return (_dead);
}