/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** dot
*/

#include "myUtils.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

float Vector2D::dot(const sf::Vector2f &vec1, const sf::Vector2f &vec2)
{
    return (vec1.x * vec2.x) + (vec1.y * vec2.y);
}

float Vector3D::dot(const sf::Vector3f &vec1, const sf::Vector3f &vec2)
{
    return (vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z);
}
