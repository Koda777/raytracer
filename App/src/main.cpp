/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** main
*/

#include "App.hpp"
#include "constant.hpp"
#include <exception>
#include <iostream>

int main(const int ac, const char **av)
{
    try {
        if (ac != 2)
            throw std::invalid_argument("invalid arguments");
        appEntryPoint(av[1]);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return EPITECH_ERROR;
    }
    return 0;
}
