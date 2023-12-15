/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** radians
*/

#include "myUtils.hpp"

constexpr double pi = 3.14159265358979323846;

double radians(double degrees)
{
    return degrees * pi / 180.0;
}
