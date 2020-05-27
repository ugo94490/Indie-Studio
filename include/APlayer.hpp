/*
** EPITECH PROJECT, 2020
** APlayer.hpp
** File description:
** APlayer.hpp
*/

#pragma once

#include <vector>

class APlayer
{
    public:
        enum PlayerType
        {
            Normal = 0
        };

        APlayer() = default;
        APlayer(APlayer::PlayerType);
        virtual ~APlayer() = 0;
        APlayer::PlayerType getType(void);
        std::vector<float> getPos(void);

    protected:
        APlayer::PlayerType type;
        int health;
        int speed;
        int range;
        std::vector<float> pos;
};