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

static std::vector<irr::core::rect<irr::s32>> left_button =
{
    irr::core::rect<irr::s32>(116, 803, 331, 1033),
    irr::core::rect<irr::s32>(363, 803, 578, 1033),
    irr::core::rect<irr::s32>(631, 803, 846, 1033)
};

static std::vector<irr::core::rect<irr::s32>> right_button =
{
    irr::core::rect<irr::s32>(116, 1064, 331, 1294),
    irr::core::rect<irr::s32>(363, 1064, 578, 1294),
    irr::core::rect<irr::s32>(631, 1064, 846, 1294)
};

static std::vector<irr::core::rect<irr::s32>> rectangle_rect =
{
    irr::core::rect<irr::s32>(1291, 0, 1691, 520),
    irr::core::rect<irr::s32>(1291, 0, 1691, 520),
    irr::core::rect<irr::s32>(1291, 0, 1691, 520)
};

#endif /* !RECT_HPP_ */