/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** MultilpyColor
*/

#include "myUtils.hpp"
#include <SFML/Graphics.hpp>

sf::Color operator*(const sf::Color &color, float scalar)
{
    sf::Uint8 r = static_cast<sf::Uint8>(static_cast<float>(color.r) * scalar);
    sf::Uint8 g = static_cast<sf::Uint8>(static_cast<float>(color.g) * scalar);
    sf::Uint8 b = static_cast<sf::Uint8>(static_cast<float>(color.b) * scalar);
    sf::Uint8 a = static_cast<sf::Uint8>(static_cast<float>(color.a));
    return sf::Color(r, g, b, a);
}

sf::Color operator/(const sf::Color &color, int scalar)
{
    sf::Uint8 r = static_cast<sf::Uint8>(static_cast<float>(color.r) / scalar);
    sf::Uint8 g = static_cast<sf::Uint8>(static_cast<float>(color.g) / scalar);
    sf::Uint8 b = static_cast<sf::Uint8>(static_cast<float>(color.b) / scalar);
    sf::Uint8 a = static_cast<sf::Uint8>(static_cast<float>(color.a) / scalar);
    return sf::Color(r, g, b, a);
}
