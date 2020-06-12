/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Save
*/

#pragma once

#include "Exception.hpp"
#include "SolidWall.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

template<typename T>
class Save {
    public:
        static std::vector<std::string> readfile(std::string const &filepath) {
            std::vector<std::string> tab;
            std::string line;
            std::ifstream in(filepath);

            if (!in.is_open()) {
                throw (Exception("Could not load file\n"));
                return (tab);
            }
            while (getline(in,line))
                tab.push_back(line);
            in.close();
            return (tab);
        }
        static void save(T const &arg, std::ofstream &stream) {
            stream << arg << std::endl;
        }
};