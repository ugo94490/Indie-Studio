/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** Rect
*/

#ifndef RECT_HPP_
#define RECT_HPP_

#include <irrlicht.h>
#include <vector>

static std::vector<irr::core::rect<irr::s32>> right_rect =
{
    irr::core::rect<irr::s32>(0, 1914, 214, 2143),
    irr::core::rect<irr::s32>(247, 1914, 461, 2143),
    irr::core::rect<irr::s32>(515, 1914, 729, 2143)
};

static std::vector<irr::core::rect<irr::s32>> left_rect =
{
    irr::core::rect<irr::s32>(0, 2144, 214, 2374),
    irr::core::rect<irr::s32>(247, 2144, 461, 2374),
    irr::core::rect<irr::s32>(515, 2144, 729, 2374)
};

static std::vector<irr::core::rect<irr::s32>> play_rect =
{
    irr::core::rect<irr::s32>(0, 0, 400, 173),
    irr::core::rect<irr::s32>(445, 0, 845, 173),
    irr::core::rect<irr::s32>(890, 0, 1290, 173)
};

static std::vector<irr::core::rect<irr::s32>> quit_rect =
{
    irr::core::rect<irr::s32>(0, 174, 400, 347),
    irr::core::rect<irr::s32>(445, 174, 845, 347),
    irr::core::rect<irr::s32>(890, 174, 1290, 347)
};

static std::vector<irr::core::rect<irr::s32>> options_rect =
{
    irr::core::rect<irr::s32>(0, 348, 400, 521),
    irr::core::rect<irr::s32>(445, 348, 845, 521),
    irr::core::rect<irr::s32>(890, 348, 1290, 521)
};

static std::vector<irr::core::rect<irr::s32>> credit_rect =
{
    irr::core::rect<irr::s32>(0, 522, 400, 695),
    irr::core::rect<irr::s32>(445, 522, 845, 695),
    irr::core::rect<irr::s32>(890, 522, 1290, 695)
};

static std::vector<irr::core::rect<irr::s32>> score_rect =
{
    irr::core::rect<irr::s32>(0, 696, 400, 869),
    irr::core::rect<irr::s32>(445, 696, 845, 869),
    irr::core::rect<irr::s32>(890, 696, 1290, 869)
};

static std::vector<irr::core::rect<irr::s32>> rules_rect =
{
    irr::core::rect<irr::s32>(0, 870, 400, 1043),
    irr::core::rect<irr::s32>(445, 870, 845, 1043),
    irr::core::rect<irr::s32>(890, 870, 1290, 1043)
};

static std::vector<irr::core::rect<irr::s32>> back_rect =
{
    irr::core::rect<irr::s32>(0, 1044, 400, 1217),
    irr::core::rect<irr::s32>(445, 1044, 845, 1217),
    irr::core::rect<irr::s32>(890, 1044, 1290, 1217)
};

static std::vector<irr::core::rect<irr::s32>> new_rect =
{
    irr::core::rect<irr::s32>(0, 1218, 400, 1391),
    irr::core::rect<irr::s32>(445, 1218, 845, 1391),
    irr::core::rect<irr::s32>(890, 1218, 1290, 1391)
};

static std::vector<irr::core::rect<irr::s32>> load_rect =
{
    irr::core::rect<irr::s32>(0, 1392, 400, 1565),
    irr::core::rect<irr::s32>(445, 1392, 845, 1565),
    irr::core::rect<irr::s32>(890, 1392, 1290, 1565)
};

static std::vector<irr::core::rect<irr::s32>> menu_rect =
{
    irr::core::rect<irr::s32>(0, 1566, 400, 1739),
    irr::core::rect<irr::s32>(445, 1566, 845, 1739),
    irr::core::rect<irr::s32>(890, 1566, 1290, 1739)
};

static std::vector<irr::core::rect<irr::s32>> rectangle_rect =
{
    irr::core::rect<irr::s32>(1291, 0, 1691, 520),
    irr::core::rect<irr::s32>(1291, 0, 1691, 520),
    irr::core::rect<irr::s32>(1291, 0, 1691, 520)
};

static std::vector<irr::core::rect<irr::s32>> name_rect =
{
    irr::core::rect<irr::s32>(1291, 520, 1691, 620),
    irr::core::rect<irr::s32>(1291, 520, 1691, 620),
    irr::core::rect<irr::s32>(1291, 520, 1691, 620)
};

static std::vector<irr::core::rect<irr::s32>> input_rect =
{
    irr::core::rect<irr::s32>(64, 160, 464, 260),
    irr::core::rect<irr::s32>(528, 160, 928, 260),
    irr::core::rect<irr::s32>(992, 160, 1392, 260),
    irr::core::rect<irr::s32>(1456, 160, 1856, 260)
};

static std::vector<irr::core::rect<irr::s32>> input_name_rect =
{
    irr::core::rect<irr::s32>(164, 60, 464, 160),
    irr::core::rect<irr::s32>(628, 60, 928, 160),
    irr::core::rect<irr::s32>(1092, 60, 1392, 160),
    irr::core::rect<irr::s32>(1556, 60, 1856, 160)
};

static irr::core::rect<irr::s32> white_rect =
{
    irr::core::rect<irr::s32>(0, 0, 395, 510)
};

static irr::core::rect<irr::s32> black_rect =
{
    irr::core::rect<irr::s32>(0, 0, 219, 510)
};

static irr::core::rect<irr::s32> green_rect =
{
    irr::core::rect<irr::s32>(0, 0, 246, 510)
};

static irr::core::rect<irr::s32> red_rect =
{
    irr::core::rect<irr::s32>(0, 0, 311, 510)
};

static irr::core::rect<irr::s32> blue_rect =
{
    irr::core::rect<irr::s32>(0, 0, 230, 510)
};

static std::vector<irr::core::rect<irr::s32>> touche_rect =
{
    irr::core::rect<irr::s32>(1291, 621, 1391, 721),
    irr::core::rect<irr::s32>(1291, 621, 1391, 721),
    irr::core::rect<irr::s32>(1291, 621, 1391, 721)
};

static std::vector<std::vector<irr::core::position2d<irr::s32>>> pos_bind =
{
    {
        irr::core::position2d<irr::s32>(430, 40),
        irr::core::position2d<irr::s32>(320, 150),
        irr::core::position2d<irr::s32>(430, 150),
        irr::core::position2d<irr::s32>(540, 150),
        irr::core::position2d<irr::s32>(430, 260)
    },
    {
        irr::core::position2d<irr::s32>(1390, 40),
        irr::core::position2d<irr::s32>(1280, 150),
        irr::core::position2d<irr::s32>(1390, 150),
        irr::core::position2d<irr::s32>(1500, 150),
        irr::core::position2d<irr::s32>(1390, 260)
    },
    {
        irr::core::position2d<irr::s32>(430, 440),
        irr::core::position2d<irr::s32>(320, 550),
        irr::core::position2d<irr::s32>(430, 550),
        irr::core::position2d<irr::s32>(540, 550),
        irr::core::position2d<irr::s32>(430, 660)
    },
    {
        irr::core::position2d<irr::s32>(1390, 440),
        irr::core::position2d<irr::s32>(1280, 550),
        irr::core::position2d<irr::s32>(1390, 550),
        irr::core::position2d<irr::s32>(1500, 550),
        irr::core::position2d<irr::s32>(1390, 660)
    }
};

static std::vector<std::vector<irr::core::rect<irr::s32>>> pos_bind_rect =
{
    {
        irr::core::rect<irr::s32>(430, 40, 530, 140),
        irr::core::rect<irr::s32>(320, 150, 420, 250),
        irr::core::rect<irr::s32>(430, 150, 530, 250),
        irr::core::rect<irr::s32>(540, 150, 640, 250),
        irr::core::rect<irr::s32>(430, 260, 530, 360)
    },
    {
        irr::core::rect<irr::s32>(1390, 40, 1490, 140),
        irr::core::rect<irr::s32>(1280, 150, 1380, 250),
        irr::core::rect<irr::s32>(1390, 150, 1490, 250),
        irr::core::rect<irr::s32>(1500, 150, 1600, 250),
        irr::core::rect<irr::s32>(1390, 260, 1490, 360)
    },
    {
        irr::core::rect<irr::s32>(430, 440, 530, 540),
        irr::core::rect<irr::s32>(320, 550, 420, 650),
        irr::core::rect<irr::s32>(430, 550, 530, 650),
        irr::core::rect<irr::s32>(540, 550, 640, 650),
        irr::core::rect<irr::s32>(430, 660, 530, 760)
    },
    {
        irr::core::rect<irr::s32>(1390, 440, 1490, 540),
        irr::core::rect<irr::s32>(1280, 550, 1380, 650),
        irr::core::rect<irr::s32>(1390, 550, 1490, 650),
        irr::core::rect<irr::s32>(1500, 550, 1600, 650),
        irr::core::rect<irr::s32>(1390, 660, 1490, 760)
    }
};

static std::vector<std::vector<std::pair<bool, char>>> bind_p =
{
    {{false, 'z'}, {false, 'q'}, {false, 's'}, {false, 'd'}, {false, 'a'}},
    {{false, 't'}, {false, 'f'}, {false, 'g'}, {false, 'h'}, {false, 'r'}},
    {{false, 'i'}, {false, 'j'}, {false, 'k'}, {false, 'l'}, {false, 'u'}},
    {{false, 'w'}, {false, 'x'}, {false, 'c'}, {false, 'v'}, {false, 'b'}}
};

static std::vector<std::string> name_p =
{
    "Player1",
    "Player2",
    "Player3",
    "Player4"
};

#endif /* !RECT_HPP_ */