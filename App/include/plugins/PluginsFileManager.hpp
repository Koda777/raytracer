/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PluginsFileManager
*/

#pragma once
#include "pluginDesc.hpp"
#include <string>
#include <vector>

class PluginsFileManager
{
    private:
        std::string m_path;
        std::vector<PluginDesc> m_availablePlugins;

    public:
        PluginsFileManager(const std::string &path);
        ~PluginsFileManager();

        void refreshAvailablePlugin();
        void displayAvailableLib();
        PluginDesc getLibByName(const std::string &name);
};
