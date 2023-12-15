/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ConfigDefault
*/

#pragma once
#include "Material.hpp"

struct ConfigPrimitive
{
        struct ConfigMaterial
        {
                sf::Color albedo;
                float roughness;
        };

        std::string identifier;
        sf::Vector3f position;
        sf::Vector3f normal;
        float radius = 0.f;
        float height = 0.f;
        ConfigMaterial material;
};

struct ConfigLight
{
        std::string identifier;
        sf::Vector3f position = {0, 0, 0};
        float intensity = 1.f;
};

struct ConfigCamera
{
        std::string identifier;
        int fov = 50;
        int width = 800;
        int height = 800;
        sf::Vector3f position = {0, 0, 3};
        sf::Vector3f direction = {0, 0, -1};
        sf::Vector3f rotation = {0, 0, 0};
};

struct ConfigRenderer
{
        sf::Color backgroundColor = sf::Color(135, 206, 235);
        int bounces = 5;
        float multiplier = 1.0;
};

struct ConfigApp
{
        bool gui = true;
        std::string outputFile;
        int maxFps = 144;
        float sleepTime = 0.f;
};

// operator overloads
std::ostream &operator<<(std::ostream &os, const ConfigPrimitive &configPrimitive);
std::ostream &operator<<(std::ostream &os, const ConfigLight &configLight);
std::ostream &operator<<(std::ostream &os, const ConfigCamera &configCamera);
std::ostream &operator<<(std::ostream &os, const ConfigRenderer &config);
std::ostream &operator<<(std::ostream &os, const ConfigApp &config);