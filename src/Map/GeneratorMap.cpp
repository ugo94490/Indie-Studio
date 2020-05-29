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
            for (int x = 1; x != xMax - 1; x++)
                _map[y][x] = 'O';
            next = false;
            continue;
        }
        _map[y][1] = ' ';
        for (int x = 2; x != xMax - 1; x++) {
            if (x % 2 == 0 || x % 2 == 2)
                _map[y][x] = 'X';
            else
                _map[y][x] = 'O';
        }
        next = true;
    }
}

int GeneratorMap::countWall()
{
/*     int count = 0;

    for (int y = 0; y != yMax; y++) {
        for (int x = 0; x != xMax; x++)
            if (_map[y][x] == 'X')
                count++;
    }
    return count / 3; */
    return 0;
}

void GeneratorMap::randomWall()
{
    /* int random = rand() % (4 - 1) + 1;
    int nbWall = countWall(); */

    for (int y = 1; y != yMax - 1; y++) {
        for (int x = 1; x != xMax - 1; x++) {
            if (_map[y][x] != 'X' && std::rand() % (4 - 1) + 1 == 2)
                _map[y][x] = ' ';
        }
    }
}

void GeneratorMap::createMap()
{
    writeBorder();
    randomWall();
    saveMap();
}

void GeneratorMap::saveMap()
{
    std::ofstream myfile;

    myfile.open("assets/Map/random_map.txt");
    for (auto line : _map)
        myfile << line.c_str();
    myfile.close();
}

GeneratorMap::~GeneratorMap()
{

}