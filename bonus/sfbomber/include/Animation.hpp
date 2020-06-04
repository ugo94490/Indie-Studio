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

// WhiteBomber
static const std::vector<mystruct::intRect> _whiteBomberUpRects = {
    {16, 0, 15, 23},
    {32, 0, 15, 23},
    {16, 0, 15, 23},
    {0, 0, 15, 23}
};

static const std::vector<mystruct::intRect> _whiteBomberLeftRects = {
    {16, 24, 16, 25},
    {33, 24, 16, 25},
    {16, 24, 16, 25},
    {0, 24, 15, 25}
};

static const std::vector<mystruct::intRect> _whiteBomberDownRects = {
    {16, 50, 15, 24},
    {32, 50, 15, 24},
    {16, 50, 15, 24},
    {0, 50, 15, 24}
};
static const std::vector<mystruct::intRect> _whiteBomberRightRects = {
    {17, 75, 16, 24},
    {34, 75, 16, 24},
    {17, 75, 16, 24},
    {0, 75, 16, 24}
};
static const std::vector<mystruct::intRect> _whiteBomberDeadRects = {
    {0, 100, 15, 24},
    {16, 100, 15, 24},
    {32, 100, 15, 24},
    {48, 100, 15, 24},
    {64, 100, 15, 24},
    {80, 100, 15, 24}
};

// BlackBomber
static const std::vector<mystruct::intRect> _blackBomberUpRects = {
    {116, 0, 15, 23},
    {132, 0, 15, 23},
    {116, 0, 15, 23},
    {100, 0, 15, 23}
};

static const std::vector<mystruct::intRect> _blackBomberLeftRects = {
    {116, 24, 16, 25},
    {133, 24, 16, 25},
    {116, 24, 16, 25},
    {100, 24, 15, 25}
};

static const std::vector<mystruct::intRect> _blackBomberDownRects = {
    {116, 50, 15, 24},
    {132, 50, 15, 24},
    {116, 50, 15, 24},
    {100, 50, 15, 24}
};
static const std::vector<mystruct::intRect> _blackBomberRightRects = {
    {117, 75, 16, 24},
    {134, 75, 16, 24},
    {117, 75, 16, 24},
    {100, 75, 16, 24}
};
static const std::vector<mystruct::intRect> _blackBomberDeadRects = {
    {100, 100, 15, 24},
    {116, 100, 15, 24},
    {132, 100, 15, 24},
    {148, 100, 15, 24},
    {164, 100, 15, 24},
    {180, 100, 15, 24}
};

// BlueBomber
static const std::vector<mystruct::intRect> _blueBomberUpRects = {
    {316, 0, 15, 23},
    {332, 0, 15, 23},
    {316, 0, 15, 23},
    {300, 0, 15, 23}
};

static const std::vector<mystruct::intRect> _blueBomberLeftRects = {
    {316, 24, 16, 25},
    {333, 24, 16, 25},
    {316, 24, 16, 25},
    {300, 24, 15, 25}
};

static const std::vector<mystruct::intRect> _blueBomberDownRects = {
    {316, 50, 15, 24},
    {332, 50, 15, 24},
    {316, 50, 15, 24},
    {300, 50, 15, 24}
};
static const std::vector<mystruct::intRect> _blueBomberRightRects = {
    {317, 75, 16, 24},
    {334, 75, 16, 24},
    {317, 75, 16, 24},
    {300, 75, 16, 24}
};
static const std::vector<mystruct::intRect> _blueBomberDeadRects = {
    {300, 100, 15, 24},
    {316, 100, 15, 24},
    {332, 100, 15, 24},
    {348, 100, 15, 24},
    {364, 100, 15, 24},
    {380, 100, 15, 24}
};

// OrangeBomber
static const std::vector<mystruct::intRect> _orangeBomberUpRects = {
    {216, 0, 15, 23},
    {232, 0, 15, 23},
    {216, 0, 15, 23},
    {200, 0, 15, 23}
};

static const std::vector<mystruct::intRect> _orangeBomberLeftRects = {
    {216, 24, 16, 25},
    {233, 24, 16, 25},
    {216, 24, 16, 25},
    {200, 24, 15, 25}
};

static const std::vector<mystruct::intRect> _orangeBomberDownRects = {
    {216, 50, 15, 24},
    {232, 50, 15, 24},
    {216, 50, 15, 24},
    {200, 50, 15, 24}
};
static const std::vector<mystruct::intRect> _orangeBomberRightRects = {
    {217, 75, 16, 24},
    {234, 75, 16, 24},
    {217, 75, 16, 24},
    {200, 75, 16, 24}
};
static const std::vector<mystruct::intRect> _orangeBomberDeadRects = {
    {200, 100, 15, 24},
    {216, 100, 15, 24},
    {232, 100, 15, 24},
    {248, 100, 15, 24},
    {264, 100, 15, 24},
    {280, 100, 15, 24}
};

// Terrain
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

// Bomb and explosions
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

// Powerups
static const std::vector<mystruct::intRect> _bombPowerupRects = {
    {0, 287, 16, 16}
};

static const std::vector<mystruct::intRect> _firePowerupRects = {
    {17, 287, 16, 16}
};

static const std::vector<mystruct::intRect> _rollerPowerupRects = {
    {34, 287, 16, 16}
};

static const std::vector<mystruct::intRect> _throughwallPowerupRects = {
    {51, 287, 16, 16}
};

class Animation {
    public:
        Animation() = default;
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


// WhiteBomber
static const Animation whiteBomberUpAnim(_whiteBomberUpRects, 300, true, false, 0);
static const Animation whiteBomberLeftAnim(_whiteBomberLeftRects, 300, true, false, 0);
static const Animation whiteBomberDownAnim(_whiteBomberDownRects, 300, true, false, 0);
static const Animation whiteBomberRightAnim(_whiteBomberRightRects, 300, true, false, 0);
static const Animation whiteBomberDeadAnim(_whiteBomberDeadRects, 300, true, true, 1);
static const std::vector<Animation> whiteBomberAnims = {
    whiteBomberUpAnim,
    whiteBomberLeftAnim,
    whiteBomberRightAnim,
    whiteBomberDownAnim,
    whiteBomberDeadAnim
};

// BlackBomber
static const Animation blackBomberUpAnim(_blackBomberUpRects, 300, true, false, 0);
static const Animation blackBomberLeftAnim(_blackBomberLeftRects, 300, true, false, 0);
static const Animation blackBomberDownAnim(_blackBomberDownRects, 300, true, false, 0);
static const Animation blackBomberRightAnim(_blackBomberRightRects, 300, true, false, 0);
static const Animation blackBomberDeadAnim(_blackBomberDeadRects, 300, true, true, 1);
static const std::vector<Animation> blackBomberAnims = {
    blackBomberUpAnim,
    blackBomberLeftAnim,
    blackBomberRightAnim,
    blackBomberDownAnim,
    blackBomberDeadAnim
};

// BlueBomber
static const Animation blueBomberUpAnim(_blueBomberUpRects, 300, true, false, 0);
static const Animation blueBomberLeftAnim(_blueBomberLeftRects, 300, true, false, 0);
static const Animation blueBomberDownAnim(_blueBomberDownRects, 300, true, false, 0);
static const Animation blueBomberRightAnim(_blueBomberRightRects, 300, true, false, 0);
static const Animation blueBomberDeadAnim(_blueBomberDeadRects, 300, true, true, 1);
static const std::vector<Animation> blueBomberAnims = {
    blueBomberUpAnim,
    blueBomberLeftAnim,
    blueBomberRightAnim,
    blueBomberDownAnim,
    blueBomberDeadAnim
};

// OrangeBomber
static const Animation orangeBomberUpAnim(_orangeBomberUpRects, 300, true, false, 0);
static const Animation orangeBomberLeftAnim(_orangeBomberLeftRects, 300, true, false, 0);
static const Animation orangeBomberDownAnim(_orangeBomberDownRects, 300, true, false, 0);
static const Animation orangeBomberRightAnim(_orangeBomberRightRects, 300, true, false, 0);
static const Animation orangeBomberDeadAnim(_orangeBomberDeadRects, 300, true, true, 1);
static const std::vector<Animation> orangeBomberAnims = {
    orangeBomberUpAnim,
    orangeBomberLeftAnim,
    orangeBomberRightAnim,
    orangeBomberDownAnim,
    orangeBomberDeadAnim
};

// Terrain
static const Animation breakableWallAnim(_BreakableWallRects, 100, false, true, 1);
static const Animation solidWallAnim(_SolidWallRects, 0);
static const Animation groundAnim(_GroundRects, 0);

// Bomb and explosion
static const Animation bombAnim(_bombRects, 300, true, true, 5);
static const Animation centerExplosionAnim(_centerExplosionRects, 100, true, true, 1);
static const Animation upDownExplosionAnim(_upDownExplosionRects, 100, true, true, 1);
static const Animation leftRightExplosionAnim(_leftRightExplosionRects, 100, true, true, 1);
static const Animation downExplosionAnim(_downExplosionRects, 100, true, true, 1);
static const Animation leftExplosionAnim(_leftExplosionRects, 100, true, true, 1);
static const Animation upExplosionAnim(_upExplosionRects, 100, true, true, 1);
static const Animation rightExplosionAnim(_rightExplosionRects, 100, true, true, 1);

// PowerUps
static const Animation bombUpAnim(_bombPowerupRects, 0);
static const Animation fireUpAnim(_firePowerupRects, 0);
static const Animation speedUpAnim(_rollerPowerupRects, 0);
static const Animation throughwallUpAnim(_throughwallPowerupRects, 0);