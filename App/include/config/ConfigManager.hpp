/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ConfigManager
*/

#pragma once
#include "ConfigDefault.hpp"
#include <libconfig.h++>

class ConfigManager
{
    public:
        using PrimitiveConfigList = std::vector<ConfigPrimitive>;
        using LightConfigList = std::vector<ConfigLight>;

    private:
        libconfig::Config config;
        std::string m_configFileName;

        PrimitiveConfigList m_primitiveConfigList;
        LightConfigList m_lightConfigList;
        ConfigCamera m_configCamera;
        ConfigRenderer m_configRenderer;
        ConfigApp m_configApp;

        void parsePrimitives();
        void parseLights();
        void parseCamera();
        void parseRenderer();
        void parseApp();

    public:
        ConfigManager(const std::string configFile);
        ~ConfigManager() = default;

        void parse();
        void displayConfig();

        friend class App;
};
