/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Scene
*/

#include "graphical/Scene.hpp"

Scene::Scene(ConfigManager::PrimitiveConfigList &primitivesConfig, ConfigManager::LightConfigList &lightsConfig) : m_primitivesConfig{primitivesConfig}, m_lightsConfig{lightsConfig} {}

Scene::~Scene() {}

void Scene::load(IPrimitiveFactory &primitiveFactory, ILightFactory &lightFactory)
{
    for (auto &light : m_lightsConfig) {
        m_lights.push_back(lightFactory.create(light.identifier));
        m_lights.back()->setPosition(light.position).setIntensity(light.intensity);
    }

    for (auto &primitive : m_primitivesConfig) {
        m_primitives.push_back(primitiveFactory.create(primitive.identifier));
        m_materials.push_back(Material{primitive.material.albedo, primitive.material.roughness});
        m_primitives.back()->setHeight(primitive.height).setRadius(primitive.radius).setPosition(primitive.position).setNormal(primitive.normal).setMaterial(m_materials.back());
    }
}

int Scene::getPrimitiveSize() const
{
    return m_primitives.size();
}

std::reference_wrapper<IPrimitive> Scene::getPrimitive(unsigned int index) const
{
    if (index >= m_primitives.size())
        throw std::runtime_error("Scene::getPrimitive out of range");
    return std::ref(*m_primitives[index]);
}

const LightVector &Scene::getLight() const
{
    return m_lights;
}
