/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Save
*/

#pragma once

#include "Exception.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

template<typename T>
class Save {
    public:
        static void save(T const &arg, std::ofstream &stream) {
            stream << arg << std::endl;
        }
};