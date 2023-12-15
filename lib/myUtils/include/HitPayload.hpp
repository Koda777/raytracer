/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** HitPayload
*/

#pragma once
#include <SFML/Graphics.hpp>

struct HitPayload
{
        float hitDistance;
        sf::Vector3f worldPosition;
        sf::Vector3f worldNormal;
        int objectIndex;
};
