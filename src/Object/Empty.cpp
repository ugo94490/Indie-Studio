/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** Empty
*/

#include "Empty.hpp"

Empty::Empty(float posx, float posy)
{
    _type = ObjectType::Empty;
    _pos = {posx, 0, posy};
}

Empty::~Empty()
{
}