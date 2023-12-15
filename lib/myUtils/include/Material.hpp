/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Material
*/

#pragma once
#include <SFML/Graphics.hpp>

struct Material
{
        sf::Color albedo;
        float roughness;
};
