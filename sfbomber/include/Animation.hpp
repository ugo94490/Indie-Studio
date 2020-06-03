/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Animation
*/

#pragma once

#include <vector>
#include <chrono>
#include "Structs.hpp"

static const std::vector<mystruct::intRect> _GroundRects = {
    {51, 304, 16, 16}
};

static const std::vector<mystruct::intRect> _SolidWallRects = {
    {17, 304, 16, 16}
};

static const std::vector<mystruct::intRect> _BreakableWallRects = {
    {0, 321, 16, 16},
    {17, 321, 16, 16},
    {34, 321, 16, 16},
    {51, 321, 16, 16},
    {68, 321, 16, 16},
    {85, 321, 16, 16}
};

static const std::vector<mystruct::intRect> _player1UpRects = {
    {16, 0, 15, 23},
    {32, 0, 15, 23},
    {16, 0, 15, 23},
    {0, 0, 15, 23}
};

static const std::vector<mystruct::intRect> _player1LeftRects = {
    {16, 24, 16, 25},
    {33, 24, 16, 25},
    {16, 24, 16, 25},
    {0, 24, 15, 25}
};

static const std::vector<mystruct::intRect> _player1DownRects = {
    {16, 50, 15, 24},
    {32, 50, 15, 24},
    {16, 50, 15, 24},
    {0, 50, 15, 24}
};

static const std::vector<mystruct::intRect> _player1RightRects = {
    {17, 75, 16, 24},
    {34, 75, 16, 24},
    {17, 75, 16, 24},
    {0, 75, 16, 24}
};

static const std::vector<mystruct::intRect> _player1DeadRects = {
    {0, 100, 15, 24},
    {16, 100, 15, 24},
    {32, 100, 15, 24},
    {48, 100, 15, 24},
    {64, 100, 15, 24},
    {80, 100, 15, 24}
};

static const std::vector<mystruct::intRect> _bombRects = {
    {0, 270, 16, 16},
    {17, 270, 16, 16},
    {34, 270, 16, 16},
    {17, 270, 16, 16}
};

static const std::vector<mystruct::intRect> _centerExplosionRects = {
    {51, 151, 16, 16},
    {34, 151, 16, 16},
    {17, 151, 16, 16},
    {0, 151, 16, 16},
    {17, 151, 16, 16},
    {34, 151, 16, 16},
    {51, 151, 16, 16}
};

static const std::vector<mystruct::intRect> _upDownExplosionRects = {
    {51, 168, 16, 16},
    {34, 168, 16, 16},
    {17, 168, 16, 16},
    {0, 168, 16, 16},
    {17, 168, 16, 16},
    {34, 168, 16, 16},
    {51, 168, 16, 16}
};

static const std::vector<mystruct::intRect> _leftRightExplosionRects = {
    {51, 185, 16, 16},
    {34, 185, 16, 16},
    {17, 185, 16, 16},
    {0, 185, 16, 16},
    {17, 185, 16, 16},
    {34, 185, 16, 16},
    {51, 185, 16, 16}
};

static const std::vector<mystruct::intRect> _downExplosionRects = {
    {51, 202, 16, 16},
    {34, 202, 16, 16},
    {17, 202, 16, 16},
    {0, 202, 16, 16},
    {17, 202, 16, 16},
    {34, 202, 16, 16},
    {51, 202, 16, 16}
};

static const std::vector<mystruct::intRect> _leftExplosionRects = {
    {51, 219, 16, 16},
    {34, 219, 16, 16},
    {17, 219, 16, 16},
    {0, 219, 16, 16},
    {17, 219, 16, 16},
    {34, 219, 16, 16},
    {51, 219, 16, 16}
};

static const std::vector<mystruct::intRect> _upExplosionRects = {
    {51, 236, 16, 16},
    {34, 236, 16, 16},
    {17, 236, 16, 16},
    {0, 236, 16, 16},
    {17, 236, 16, 16},
    {34, 236, 16, 16},
    {51, 236, 16, 16}
};

static const std::vector<mystruct::intRect> _rightExplosionRects = {
    {51, 253, 16, 16},
    {34, 253, 16, 16},
    {17, 253, 16, 16},
    {0, 253, 16, 16},
    {17, 253, 16, 16},
    {34, 253, 16, 16},
    {51, 253, 16, 16}
};

class Animation {
    public:
        Animation(std::vector<mystruct::intRect> rects, unsigned int time_frame, bool do_anim = false, bool destroy = false, unsigned int nb_cycles = 0);
        ~Animation();
        void setDoAnim(bool do_anim);
        bool getDestroy() const;
        unsigned int getNbCycles() const;
        mystruct::intRect getActualRect() const;
        void update();

    protected:
    private:
        bool _destroy;
        bool _do_anim;
        unsigned int _nb_cycles;
        unsigned int _time_frame;
        unsigned int _actual_frame;
        std::vector<mystruct::intRect> _rects;
        std::chrono::steady_clock::time_point _start;
        std::chrono::steady_clock::time_point _end;
};

static const Animation player1UpAnim(_player1UpRects, 300, true, false, 0);
static const Animation player1LeftAnim(_player1LeftRects, 300, true, false, 0);
static const Animation player1DownAnim(_player1DownRects, 300, true, false, 0);
static const Animation player1RightAnim(_player1RightRects, 300, true, false, 0);
static const Animation player1DeadAnim(_player1DeadRects, 300, true, true, 1);
static const std::vector<Animation> player1Anims = {
    player1UpAnim,
    player1LeftAnim,
    player1RightAnim,
    player1DownAnim,
    player1DeadAnim
};
static const Animation breakableWallAnim(_BreakableWallRects, 100, false, true, 1);
static const Animation solidWallAnim(_SolidWallRects, 0);
static const Animation groundAnim(_GroundRects, 0);
static const Animation bombAnim(_bombRects, 300, true, true, 5);
static const Animation centerExplosionAnim(_centerExplosionRects, 100, true, true, 1);
static const Animation upDownExplosionAnim(_upDownExplosionRects, 100, true, true, 1);
static const Animation leftRightExplosionAnim(_leftRightExplosionRects, 100, true, true, 1);
static const Animation downExplosionAnim(_downExplosionRects, 100, true, true, 1);
static const Animation leftExplosionAnim(_leftExplosionRects, 100, true, true, 1);
static const Animation upExplosionAnim(_upExplosionRects, 100, true, true, 1);
static const Animation rightExplosionAnim(_rightExplosionRects, 100, true, true, 1);
