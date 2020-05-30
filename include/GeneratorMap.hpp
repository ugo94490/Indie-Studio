/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** GeneratorMap
*/

#ifndef GENERATORMAP_HPP_
#define GENERATORMAP_HPP_

#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>

class GeneratorMap {
    public:
        GeneratorMap(int y, int x);
        void writeBorder();
        int countWall();
        void randomWall();
        void createMap();
        void removeFinalWall();
        void saveMap();
        ~GeneratorMap();

    private:
        std::vector<std::string> _map;
        int xMax;
        int yMax;
};

#endif /* !GENERATORMAP_HPP_ */
