/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** sfDisplay
*/

#include "myUtils.hpp"

std::ostream &operator<<(std::ostream &os, const sf::Color &color)
{
    os << (int)color.r << ", " << (int)color.g << ", " << (int)color.b << ", " << (int)color.a;
    return os;
}

std::ostream &operator<<(std::ostream &os, const sf::Vector3f &vector)
{
    os << vector.x << ", " << vector.y << ", " << vector.z;
    return os;
}
