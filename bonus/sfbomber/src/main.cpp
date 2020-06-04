/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** main
*/

#include "MainLoop.hpp"

int main(int ac, char **av, char **env)
{
    MainLoop loop;
    std::srand(time(nullptr));

    if (!env || !env[0])
        return (84);
    loop.do_loop();
    return (0);
}