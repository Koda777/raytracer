/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** myUtils
*/

#pragma once
#include <SFML/Graphics.hpp>

namespace Vector2D
{

    float dot(const sf::Vector2f &vec1, const sf::Vector2f &vec2);

    sf::Vector2f normalize(const sf::Vector2f &vector);

    sf::Vector2f reflect(const sf::Vector2f &vect1, const sf::Vector2f &vec2);

}; // namespace Vector2D

namespace Vector3D
{

    float dot(const sf::Vector3f &vec1, const sf::Vector3f &vec2);

    sf::Vector3f normalize(const sf::Vector3f &vector);

    sf::Vector3f reflect(const sf::Vector3f &vect1, const sf::Vector3f &vec2);

}; // namespace Vector3D

double radians(double degrees);
sf::Color operator*(const sf::Color &color, float scalar);
sf::Color operator/(const sf::Color &color, int scalar);
std::ostream &operator<<(std::ostream &os, const sf::Color &color);
std::ostream &operator<<(std::ostream &os, const sf::Vector3f &vector);

// generate filename
std::string generateUniqueFilename(const std::string &extension, const std::string &directoryPath = "");
