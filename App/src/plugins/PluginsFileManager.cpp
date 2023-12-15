/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PluginsFileManager
*/

#include "plugins/PluginsFileManager.hpp"
#include <algorithm>
#include <filesystem>
#include <iostream>
#include <map>
#include <stdexcept>

std::map<std::string, PluginDesc::PluginDescType> plugins_register{
    {"raytracer_primitive.so", PluginDesc::PRIMITIVE},
    {"raytracer_light.so", PluginDesc::LIGHT},
    {"raytracer_camera.so", PluginDesc::CAMERA},
};

PluginsFileManager::PluginsFileManager(const std::string &path) : m_path{path}
{
    refreshAvailablePlugin();
}

PluginsFileManager::~PluginsFileManager() {}

void PluginsFileManager::refreshAvailablePlugin()
{
    m_availablePlugins.clear();
    for (const auto &entry : std::filesystem::directory_iterator(m_path)) {
        if (!std::filesystem::is_regular_file(entry))
            continue;
        std::string name = std::filesystem::path(entry.path()).filename().string();
        PluginDesc new_plugin = {
            .name = name,
            .path = entry.path().string(),
            .type = (plugins_register.count(name) > 0) ? plugins_register[name] : throw std::runtime_error("Unknown Plugin: " + name),
        };

        m_availablePlugins.push_back(new_plugin);
    }
}

void PluginsFileManager::displayAvailableLib()
{
    for (const auto &lib : m_availablePlugins) std::cout << lib.name << ": " << lib.path << std::endl;
}

PluginDesc PluginsFileManager::getLibByName(const std::string &name)
{
    auto iter = std::find_if(m_availablePlugins.begin(), m_availablePlugins.end(), [&name](const PluginDesc &m) -> bool {
        return m.name == name;
    });
    return (iter != m_availablePlugins.end()) ? *iter : PluginDesc();
}