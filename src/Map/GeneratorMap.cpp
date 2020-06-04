/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** GeneratorMap
*/

#include "GeneratorMap.hpp"

GeneratorMap::GeneratorMap(int y, int x)
{
    std::srand(std::time(nullptr));
    yMax = y;
    xMax = x;
    createMap();
}

void GeneratorMap::writeBorder()
{
    bool next = true;
    std::string line = "X";

    for (int i = 0; i != xMax; i++)
        line.append("X");
    line.append("\n");
    for (int i = 0; i != yMax; i++)
        _map.push_back(line);

    for (int y = 1; y != yMax - 1; y++) {
        if (next == true) {
            for (int x = 1; x != xMax; x++)
                _map[y][x] = 'O';
            next = false;
            continue;
        }
        _map[y][1] = ' ';
        for (int x = 2; x != xMax; x++) {
            if (x % 2 == 0 || x % 2 == 2)
                _map[y][x] = 'X';
            else
                _map[y][x] = 'O';
        }
        next = true;
    }
}

void GeneratorMap::randomWall()
{
    for (int y = 1; y != yMax - 1; y++) {
        for (int x = 1; x != xMax - 1; x++) {
            if (_map[y][x] != 'X' && std::rand() % (3 - 1) + 1 == 2)
                _map[y][x] = ' ';
        }
    }
}

void GeneratorMap::removeFinalWall()
{
    for (int y = 1; y != yMax - 1; y++) {
        if (_map[y][xMax - 1] == 'X')
            _map[y][xMax - 1] = ' ';
    }
    _map[1][1] = ' ';
    _map[1][2] = ' ';
    _map[1][3] = 'O';
    _map[2][1] = ' ';
    _map[3][1] = 'O';

    _map[yMax -2][1] = ' ';
    _map[yMax -2][2] = ' ';
    _map[yMax -2][3] = 'O';
    _map[yMax -3][1] = ' ';
    _map[yMax -4][1] = 'O';

    _map[1][xMax - 1] = ' ';
    _map[1][xMax - 2] = ' ';
    _map[1][xMax - 3] = 'O';
    _map[2][xMax - 1] = ' ';
    _map[3][xMax - 1] = 'O';

    _map[yMax - 2][xMax - 1] = ' ';
    _map[yMax - 2][xMax - 2] = ' ';
    _map[yMax - 2][xMax - 3] = 'O';
    _map[yMax - 3][xMax - 1] = ' ';
    _map[yMax - 4][xMax - 1] = 'O';
}

void GeneratorMap::createMap()
{
    writeBorder();
    randomWall();
    removeFinalWall();
    saveMap();
}

void GeneratorMap::saveMap()
{
    std::ofstream myfile;

    myfile.open("assets/map/random_map.txt");
    for (auto line : _map)
        myfile << line.c_str();
    myfile.close();
}

GeneratorMap::~GeneratorMap()
{

}