/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** reflect
*/

#include "myUtils.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

sf::Vector2f Vector2D::reflect(const sf::Vector2f &vect1, const sf::Vector2f &vec2)
{
    sf::Vector2f normalizedVec2 = Vector2D::normalize(vec2);
    return vect1 - 2.f * Vector2D::dot(vect1, normalizedVec2) * normalizedVec2;
}

sf::Vector3f Vector3D::reflect(const sf::Vector3f &vect1, const sf::Vector3f &vec2)
{
    sf::Vector3f normalizedVec2 = Vector3D::normalize(vec2);
    return vect1 - 2.f * Vector3D::dot(vect1, normalizedVec2) * normalizedVec2;
}
