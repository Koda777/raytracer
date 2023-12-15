/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** pluginsDesc
*/

#pragma once
#include <string>

struct PluginDesc
{
        enum PluginDescType {
            LIGHT,
            PRIMITIVE,
            CAMERA,
        };

        std::string name;
        std::string path;
        PluginDescType type;

        bool operator==(const PluginDesc &other) const { return type == other.type && name == other.name && path == other.path; }
};
