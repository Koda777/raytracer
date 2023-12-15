/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Scene
*/

#pragma once

#include "Material.hpp"
#include "config/ConfigManager.hpp"
#include "factory/IFactory.hpp"
#include "plugins/PluginsLoader.hpp"

using PrimitiveVector = std::vector<std::unique_ptr<IPrimitive>>;
using LightVector = std::vector<std::unique_ptr<ILight>>;
using MaterialVector = std::vector<Material>;

class Scene
{
    private:
        ConfigManager::PrimitiveConfigList &m_primitivesConfig;
        ConfigManager::LightConfigList &m_lightsConfig;
        PrimitiveVector m_primitives;
        LightVector m_lights;
        MaterialVector m_materials;

    public:
        Scene(ConfigManager::PrimitiveConfigList &, ConfigManager::LightConfigList &);
        ~Scene();

        void load(IPrimitiveFactory &, ILightFactory &);

        int getPrimitiveSize() const;
        std::reference_wrapper<IPrimitive> getPrimitive(unsigned int index) const;

        const LightVector &getLight() const;
};
