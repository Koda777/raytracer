/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** normalize
*/

#include "myUtils.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

sf::Vector2f Vector2D::normalize(const sf::Vector2f &vector)
{
    float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    if (length != 0)
        return sf::Vector2f(vector.x / length, vector.y / length);
    else
        return vector;
}

sf::Vector3f Vector3D::normalize(const sf::Vector3f &vector)
{
    float length = std::sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
    if (length != 0)
        return sf::Vector3f(vector.x / length, vector.y / length, vector.z / length);
    else
        return vector;
}
