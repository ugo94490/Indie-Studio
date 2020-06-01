/*
** EPITECH PROJECT, 2020
** APlayer.cpp
** File description:
** APlayer.cpp
*/

#include "APlayer.hpp"

APlayer::APlayer(APlayer::PlayerType)
{
}

APlayer::PlayerType APlayer::getType(void)
{
    return (type);
}

std::vector<float> APlayer::getPos(void)
{
    return (pos);
}