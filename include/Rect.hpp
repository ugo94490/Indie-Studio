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

static std::vector<std::pair<irr::EKEY_CODE, std::string>> KeyInput =
{
    {irr::KEY_KEY_A, "A"},
    {irr::KEY_KEY_B, "B"},
    {irr::KEY_KEY_C, "C"},
    {irr::KEY_KEY_D, "D"},
    {irr::KEY_KEY_E, "E"},
    {irr::KEY_KEY_F, "F"},
    {irr::KEY_KEY_G, "G"},
    {irr::KEY_KEY_H, "H"},
    {irr::KEY_KEY_I, "I"},
    {irr::KEY_KEY_J, "J"},
    {irr::KEY_KEY_K, "K"},
    {irr::KEY_KEY_L, "L"},
    {irr::KEY_KEY_M, "M"},
    {irr::KEY_KEY_N, "N"},
    {irr::KEY_KEY_O, "O"},
    {irr::KEY_KEY_P, "P"},
    {irr::KEY_KEY_Q, "Q"},
    {irr::KEY_KEY_R, "R"},
    {irr::KEY_KEY_S, "S"},
    {irr::KEY_KEY_T, "T"},
    {irr::KEY_KEY_U, "U"},
    {irr::KEY_KEY_V, "V"},
    {irr::KEY_KEY_W, "W"},
    {irr::KEY_KEY_X, "X"},
    {irr::KEY_KEY_Y, "Y"},
    {irr::KEY_KEY_Z, "Z"}
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

#endif /* !RECT_HPP_ */