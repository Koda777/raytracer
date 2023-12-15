/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** FactoryLight
*/

#include "FactoryLight.hpp"
#include "Light.hpp"
#include <functional>
#include <map>
#include <memory>
#include <string>

FactoryLight::FactoryLight()
{
    m_constructors = {
        {"ambient",
            []() {
                return std::make_unique<Light>();
            }},
        {"directional",
            []() {
                return std::make_unique<Light>();
            }},
    };
}

std::unique_ptr<ILight> FactoryLight::create(const std::string &name)
{
    if (m_constructors.count(name) == 0)
        throw std::runtime_error("Light not found " + name);
    return m_constructors[name]();
}
